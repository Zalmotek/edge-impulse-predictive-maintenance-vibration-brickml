#include "../comms.h"
#include "r_usb_pcdc_api.h"
#include "r_usb_basic.h"
#include "task.h"

#ifdef COMMS_USB

/* pvParameters contains TaskHandle_t */

#define USB_DATA_LEN              100 //    1024
#define MAX_PACKET_SIZE           64
#define LINE_CODING_LENGTH        7
#define CONTROL_LINE_STATE_LENGTH 1

//uint8_t g_buf[DATA_LEN];

typedef enum data_bits
{
    DATA_BITS_5 = 5,
    DATA_BITS_6,
    DATA_BITS_7,
    DATA_BITS_8,
    DATA_BITS_16 = 16,
}data_bits_t;

typedef enum parity_type
{
    PARITY_NONE = 0,
    PARITY_ODD,
    PARITY_EVEN,
    PARITY_MARK,
    PARITY_SPACE,
}parity_type_t;

typedef enum stop_bits
{
    STOP_BITS_1 = 0,
    STOP_BITS_1_5,
    STOP_BITS_2,
}stop_bits_t;


/* 115200 8n1 by default */
usb_pcdc_linecoding_t g_line_coding = {
    .dw_dte_rate    = (12*1000*1000), // 115200, //
    .b_char_format = STOP_BITS_1,
    .b_parity_type = PARITY_NONE,
    .b_data_bits   = DATA_BITS_8,
};

volatile usb_pcdc_ctrllinestate_t g_control_line_state = {
    .bdtr = 0,
    .brts = 0,
};

uint8_t g_comms_opened_flag = 0;

extern usb_instance_ctrl_t g_basic0_ctrl;
extern const usb_cfg_t g_basic0_cfg;

fsp_err_t comms_send_low(uint8_t * p_src, uint32_t len, uint32_t period);

void usb_cdc_rtos_callback(usb_event_info_t * event, usb_hdl_t handle, usb_onoff_t onoff)
{
    //FSP_PARAMETER_NOT_USED(event);
    FSP_PARAMETER_NOT_USED(handle);
    FSP_PARAMETER_NOT_USED(onoff);

    BaseType_t xHigherPriorityTaskWoken;

    usb_setup_t             setup;

    /* We have not woken a task at the start of the ISR. */
    xHigherPriorityTaskWoken = pdFALSE;

    switch (event->event)
    {
        case USB_STATUS_CONFIGURED :
        break;
        case USB_STATUS_WRITE_COMPLETE :
            if (pdTRUE == xSemaphoreGiveFromISR(g_usb_write_complete_binary_semaphore, &xHigherPriorityTaskWoken))
            {
                __NOP();
            }
        break;
        case USB_STATUS_READ_COMPLETE :
            if (pdTRUE == xQueueSendFromISR(g_usb_read_queue, &event->data_size, &xHigherPriorityTaskWoken ) )
            {
                __NOP();
            }

        break;
        case USB_STATUS_REQUEST : /* Receive Class Request */
            g_usb_on_usb.setupGet(event, &setup);
            if (USB_PCDC_SET_LINE_CODING == (setup.request_type & USB_BREQUEST))
            {
                g_usb_on_usb.periControlDataGet(event, (uint8_t *) &g_line_coding, LINE_CODING_LENGTH);
            }
            else if (USB_PCDC_GET_LINE_CODING == (setup.request_type & USB_BREQUEST))
            {
                g_usb_on_usb.periControlDataSet(event, (uint8_t *) &g_line_coding, LINE_CODING_LENGTH);
            }
            else if (USB_PCDC_SET_CONTROL_LINE_STATE == (event->setup.request_type & USB_BREQUEST))
            {
                fsp_err_t err = g_usb_on_usb.periControlDataGet(event, (uint8_t *) &g_control_line_state, sizeof(g_control_line_state));
                if (FSP_SUCCESS == err)
                {
                    g_control_line_state.bdtr = (unsigned char)((event->setup.request_value >> 0) & 0x01);
                    g_control_line_state.brts = (unsigned char)((event->setup.request_value >> 1) & 0x01);
                }

            }
            else
            {
                /* none */
            }
        break;
        case USB_STATUS_REQUEST_COMPLETE :
            __NOP();
        break;
        case USB_STATUS_SUSPEND :
        case USB_STATUS_DETACH :
        case USB_STATUS_DEFAULT :
            __NOP();
        break;
        default :
            __NOP();
        break;
    }

    /* We can switch context if necessary. */
    /* Actual macro used here is port specific. */
    portYIELD_FROM_ISR (xHigherPriorityTaskWoken);
}

fsp_err_t comms_open(void)
{
    fsp_err_t err;

    err = g_usb_on_usb.open(&g_basic0_ctrl, &g_basic0_cfg);
    if (FSP_SUCCESS != err)
    {
        return (err);
    }

    /* Wait for the application to open the COM port */
    while (0 == g_control_line_state.bdtr)
    {
        vTaskDelay(1);
    }

    g_comms_opened_flag = 1;
    return FSP_SUCCESS;
}

fsp_err_t comms_send(uint8_t * p_src, uint32_t len, uint32_t period)
{
    fsp_err_t       err = FSP_SUCCESS;
    uint32_t i = 0;
    uint32_t offset = 0;
    uint32_t len1 = 0;

    if (0 == g_comms_opened_flag)
        return FSP_ERR_BLE_INIT_FAILED;

#if 1
    if (len <= USB_DATA_LEN)
    {
        comms_send_low(p_src, len, period);
    }
    else
    {
        while(1)
        {
            i++;
            if (len - offset >= USB_DATA_LEN)
            {
                len1 = USB_DATA_LEN;
            }
            else
            {
                len1 = len - offset;
            }
            while(1)
            {
                err = comms_send_low(&(p_src[offset]), len1, 100);
                if (err == FSP_SUCCESS)
                {
                    break;
                }
            }
            offset += USB_DATA_LEN;
            if (offset >= len)
                break;
        }
    }
#elif 1
    comms_send_low(p_src, len, period);
#else
#endif
    return err;
}

fsp_err_t comms_send_low(uint8_t * p_src, uint32_t len, uint32_t period)
{
    fsp_err_t       err;
    uint8_t timeout = 0;

    timeout = 2;
    timeout += len/1024;
#if 1
    err = g_usb_on_usb.write(&g_basic0_ctrl, p_src, len,  USB_CLASS_PCDC);
    if (FSP_SUCCESS != err)
    {
        return  err;
    }

    /* Wait for the USB Write to complete */
#if 0
    if( xSemaphoreTake( g_usb_write_complete_binary_semaphore, portMAX_DELAY ) == pdTRUE )
    {
        __NOP();
    }
#else
    if (period != 0)
    {
        if (period == 0xFFFFFFFF)
        {
            if( xSemaphoreTake( g_usb_write_complete_binary_semaphore, portMAX_DELAY ) == pdTRUE )
            {
                __NOP();
            }
        }
        else
        {
            //vTaskDelay (period);
            if( xSemaphoreTake( g_usb_write_complete_binary_semaphore, timeout ) == pdTRUE )
            {
                __NOP();
            }
            else
            {
                err = FSP_ERR_ABORTED;
            }
        }
    }
    else
    {
        vTaskDelay (1);
    }
#endif
#else
    uint8_t pipe_num = 0;
    err = g_usb_on_usb.pipeNumberGet(&g_basic0_ctrl, &pipe_num);
    if (FSP_SUCCESS != err)
    {
        return;
    }

    err = g_usb_on_usb.pipeWrite(&g_basic0_ctrl, p_src, len, 2);
    if (FSP_SUCCESS != err)
    {
        return;
    }

#endif
    return  err;
}

fsp_err_t comms_read(uint8_t * p_dest, uint32_t * len, uint32_t timeout_milliseconds)
{
    fsp_err_t       err             = FSP_SUCCESS;
    BaseType_t      fr_err;
    TickType_t      timeout;

    if (0 == g_comms_opened_flag)
        return FSP_ERR_BLE_INIT_FAILED;

    //err = g_usb_on_usb.read(&g_basic0_ctrl, p_dest, MAX_PACKET_SIZE,  USB_CLASS_PCDC);
    err = g_usb_on_usb.read(&g_basic0_ctrl, p_dest, *len,  USB_CLASS_PCDC);
    if (FSP_SUCCESS != err)
    {
        return FSP_ERR_USB_FAILED;
    }

    if(timeout_milliseconds == portMAX_DELAY)
    {
        timeout = portMAX_DELAY;
    }
    else
    {
        timeout = timeout_milliseconds / portTICK_PERIOD_MS;
    }

    /* Wait for the USB Read to complete */
    *len = 0;
    fr_err = xQueueReceive(g_usb_read_queue, len, timeout);
    if (pdTRUE == fr_err)
    {
        return FSP_SUCCESS;
    }
    else
    {
        /* If there was a timeout, we need to terminate the USB transfer */
        //trans.type            = USB_CLASS_PCDC;
        //trans.module_number   = USB_CFG_USE_USBIP;
        //err = g_usb_on_usb.stop(&g_ctrl, USB_TRANSFER_READ, &trans);
        err = g_usb_on_usb.stop(&g_basic0_ctrl, USB_TRANSFER_READ, USB_CLASS_PCDC);

        *len = 0;

        return FSP_ERR_TIMEOUT;
    }
}

fsp_err_t comms_close(void)
{
    fsp_err_t err;

    err = g_usb_on_usb.close(&g_basic0_ctrl);
    if (FSP_SUCCESS != err)
    {
        return (err);
    }

    return FSP_SUCCESS;
}

#endif /* #ifdef COMMS_USB */
