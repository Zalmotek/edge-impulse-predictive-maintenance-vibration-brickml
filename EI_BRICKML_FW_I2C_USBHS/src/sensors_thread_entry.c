/***********************************************************************************************************************
 * Copyright [2022] RELOC s.r.l. - All rights strictly reserved
 * This Software is provided for evaluation purposes; any other use — including reproduction, modification, use for
 * a commercial product, distribution, or republication — without the prior written permission of the Copyright holder
 * is strictly prohibited.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * File Name        : sensors_thread_entry.c
 * Description      : Sensors thread.
 *********************************************************************************************************************/

#define MODULE_NAME "sensors_thread_entry"

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "common_assert.h"
#include "hal_data.h"
#include "trace_use.h"
#include "sf_bno055_api.h"
#include "sf_bno055.h"
#include "hs300x.h"
#include "threads_sync_events.h"
#include "sensors_thread_entry.h"
#include <sensors_thread_entry.h>

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

#define DEBUG_HEADER(x) { TRACE2(" %d [%s] ", xTaskGetTickCount(), x); }

#define BNO055_ENABLE    1
#define HS300X_ENABLE    1

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private function prototypes
 *********************************************************************************************************************/

void led_on(void);
void led_off(void);
void led_toggle(void);

/***************************************************************************//**
 * @brief     Transmit the data on the I2C Bus
 *
 * @param[in] buf      Address of the buffer that contains the data that have to be transmitted
 * @param[in] len      Buffer length
 * @param[in] restart  If true a restart condition is transmitted (required to read a register)
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_write( uint8_t* buf, uint32_t buf_len, bool restart );

/***************************************************************************//**
 * @brief     Receive data from the I2C Bus
 *
 * @param[in] buf      Reception Buffer Address
 * @param[in] len      Buffer length
 * @param[in] restart  If true a restart condition is transmitted
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_read( uint8_t* buf, uint32_t buf_len, bool restart );

/***************************************************************************//**
 * @brief     Read a Register Value (8-bit address) from the I2C Bus
 *
 * @param[in] reg_addr Register Address
 * @param[in] buf      Reception Buffer Address
 * @param[in] len      Buffer length
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_read_register(uint8_t reg_addr, uint8_t* buf, uint32_t buf_len);

/***************************************************************************//**
 * @brief     Initialize the I2C communication
*******************************************************************************/

fsp_err_t i2c_mst_init_communication(void);

/**********************************************************************************************************************
 * Private global variables
 *********************************************************************************************************************/

static EventGroupHandle_t i2c_sci0_event_handle = {0};
static EventGroupHandle_t i2c_riic0_event_handle = {0};
static StaticEventGroup_t i2c_sci9_event_buf = {0};
static StaticEventGroup_t i2c_riic1_event_buf = {0};

Hs300x_t Hs300x_instance = {0};

/* I2C Master on IIC Instance. */
extern const i2c_master_instance_t g_i2c_master0;

/* Motion Sensor */
static sf_bno055_ctrl_t bno055_ctrl = {0};
static const sf_bno055_cfg_t bno055_cfg = { .device = &g_i2c_master0,
                                            .reset_pin = IOPORT_PORT_00_PIN_05, //
                                            .ioport = &g_ioport,
                                            .acc_cfg = { BNO055_ACC_RANGE_4G, BNO055_ACC_BANDWIDTH_250_HZ, BNO055_ACC_UNIT_MG },
                                            .gyro_cfg = { BNO055_GYRO_RANGE_500dps, BNO055_GYRO_BANDWIDTH_230_HZ, BNO055_GYRO_UNIT_DPS },
                                            .mag_cfg = { BNO055_MAG_OUT_RATE_30_HZ, BNO055_MAG_OP_MODE_REGULAR },
                                            .temp_cfg = { BNO055_TEMP_SOURCE_ACC, BNO055_TEMP_UNIT_C } };
static sf_bno055_instance_t bno055 = { .p_ctrl = &bno055_ctrl, .p_cfg = &bno055_cfg, .p_api = &g_sf_bno055_api };

float accX = 0, accY = 0, accZ = 0;
float gyroX = 0, gyroY = 0, gyroZ = 0;
float magX = 0, magY = 0, magZ = 0;
float temperature = 0;
float humidity = 0;

/**********************************************************************************************************************
 * Functions
 *********************************************************************************************************************/
void sensors_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    fsp_err_t ret = FSP_SUCCESS;
    uint32_t i = 0;

    if (i2c_mst_init_communication() == FSP_SUCCESS)
    {
        DEBUG_HEADER("SNS");
        TRACE("Start I2C Communication\r\n");
        /* Temperature and Humidity sensor initialization */
#if HS300X_ENABLE
        ret = g_i2c_master0.p_api->slaveAddressSet( g_i2c_master0.p_ctrl, 0x44, I2C_MASTER_ADDR_MODE_7BIT );
        if (ret == FSP_SUCCESS)
        {

        }
        else
        {
            DEBUG_HEADER("SNS");
            TRACE2("HS300x KO\r\n");
        }
        Hs300x_Open(&Hs300x_instance, &g_i2c_master0, i2c_riic0_event_handle);
#endif
        /* accelerometer sensor initialization */
#if BNO055_ENABLE

        ret = g_i2c_master0.p_api->slaveAddressSet( g_i2c_master0.p_ctrl, 0x28, I2C_MASTER_ADDR_MODE_7BIT );
        ASSERT( bno055.p_api->open( bno055.p_ctrl, bno055.p_cfg ) == FSP_SUCCESS );
#endif

        while(1)
        {
            i++;
#if HS300X_ENABLE
            //ret = g_i2c_master0.p_api->abort(g_i2c_master0.p_ctrl);

            ret = g_i2c_master0.p_api->slaveAddressSet( g_i2c_master0.p_ctrl, 0x44, I2C_MASTER_ADDR_MODE_7BIT );

            ret = Hs300x_GetMeasure(&Hs300x_instance, &temperature, &humidity);
            if (ret == FSP_SUCCESS)
            {
                DEBUG_HEADER("SNS");
                TRACE2("HS300 temperature %d.%d\r\n", (int32_t)(temperature), (int32_t)(temperature*100-( ((int32_t)(temperature))*100 )));
                DEBUG_HEADER("SNS");
                TRACE2("HS300 humidity %d.%d\r\n", (int32_t)(humidity), (int32_t)(humidity*100-( ((int32_t)(humidity))*100 )));
            }
            else
            {
                DEBUG_HEADER("SNS");
                TRACE2("HS300x KO\r\n");
            }
#endif
            //ret = g_i2c_master0.p_api->abort(g_i2c_master0.p_ctrl);
#if BNO055_ENABLE
            ret = g_i2c_master0.p_api->slaveAddressSet( g_i2c_master0.p_ctrl, 0x28, I2C_MASTER_ADDR_MODE_7BIT );

                        ret  = bno055.p_api->readAccelerometer( bno055.p_ctrl, &accX, &accY, &accZ );
                        if(ret == FSP_SUCCESS)
                        {
                           TRACE2("%d,%d,%d\r\n", (int32_t)accX, (int32_t)accY, (int32_t)accZ);
                        }
                        else
                        {
                            DEBUG_HEADER("SNS");
                            TRACE2("BNO055 KO\r\n");
                        }
#endif
            if (i > 10)
            {
                i = 0;
                led_on();
                vTaskDelay(pdMS_TO_TICKS(10));
                led_off();
            }
        }
    }
    else
    {
        // error to
    }
    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}






//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// i2c
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
#define I2C_TIMEOUT_TICKS                           (1000)  /*Timeout for the I"C transmission and Reception*/
#define I2C_BUFF_TX_SIZE                            (0x10)  /*I2C Transmission Buffer Size*/
#define I2C_BUFF_RX_SIZE                            (0x50)  /*I2C Reception Buffer Size*/

static uint8_t i2c_buff_tx[I2C_BUFF_TX_SIZE] = {0};
static uint8_t i2c_buff_rx[I2C_BUFF_RX_SIZE] = {0};
static uint32_t i2c_count_tx = 0;       /*Used for debug*/
static uint32_t i2c_count_rx = 0;       /*Used for debug*/
static uint16_t i2c_cnt_rx_complete = 0;/*Used for debug*/
static uint16_t i2c_cnt_tx_complete = 0;/*Used for debug*/
static uint16_t i2c_cnt_com_error = 0;  /*Used for debug*/

static bool i2c_mst_clear_buffer_n(uint8_t* buff_p, size_t n);

fsp_err_t i2c_mst_init_communication(void)
{
    fsp_err_t ret = FSP_SUCCESS;

    /*Try to Open the connection...*/
    ret = g_i2c_master0.p_api->open(g_i2c_master0.p_ctrl, g_i2c_master0.p_cfg);

    if(ret == FSP_SUCCESS)
    {
        ret = g_i2c_master0.p_api->slaveAddressSet( g_i2c_master0.p_ctrl, 0x44, I2C_MASTER_ADDR_MODE_7BIT );
    }

    /*Clear transmission and reception buffer*/
    i2c_mst_clear_buffer_n(i2c_buff_tx, I2C_BUFF_TX_SIZE);
    i2c_mst_clear_buffer_n(i2c_buff_rx, I2C_BUFF_RX_SIZE);

    i2c_riic0_event_handle = xEventGroupCreateStatic( &i2c_riic1_event_buf );
    i2c_sci0_event_handle = xEventGroupCreateStatic( &i2c_sci9_event_buf );
    return ret;
}


fsp_err_t i2c_mst_read_register(uint8_t reg_addr, uint8_t* buf, uint32_t buf_len)
{

    fsp_err_t ret = FSP_SUCCESS;

    ret = i2c_mst_write(&reg_addr, 1, true);

    if(ret == FSP_SUCCESS)
    {
        ret = i2c_mst_read(buf, buf_len, false);
    }

    return ret;
}

fsp_err_t i2c_mst_write( uint8_t* buf, uint32_t buf_len, bool restart )
{
    fsp_err_t ret = FSP_SUCCESS;;
    EventBits_t events = {0};

    i2c_count_tx++;

    ret = g_i2c_master0.p_api->write( g_i2c_master0.p_ctrl, buf, buf_len, restart);
    FSP_ERROR_RETURN( (ret == FSP_SUCCESS), ret );

    /* Wait for TX end */
    events = xEventGroupWaitBits( i2c_riic0_event_handle,
                                  (1 << I2C_MASTER_EVENT_TX_COMPLETE),
                                  pdTRUE,
                                  pdFALSE,
                                  I2C_TIMEOUT_TICKS );

    FSP_ERROR_RETURN( ((events & (1 << I2C_MASTER_EVENT_TX_COMPLETE)) != 0), FSP_ERR_ABORTED );

    return ret;
}

fsp_err_t i2c_mst_read( uint8_t* buf, uint32_t buf_len, bool restart )
{
    fsp_err_t ret = FSP_SUCCESS;
    EventBits_t events = {0};

    i2c_count_rx++;

    ret = g_i2c_master0.p_api->read( g_i2c_master0.p_ctrl, buf, buf_len, restart);

    FSP_ERROR_RETURN( (ret == FSP_SUCCESS), ret );
    /* Wait for RX end */
    events = xEventGroupWaitBits( i2c_riic0_event_handle,
                                  (1 << I2C_MASTER_EVENT_RX_COMPLETE),
                                  pdTRUE,
                                  pdFALSE,
                                  I2C_TIMEOUT_TICKS );
    FSP_ERROR_RETURN( ((events & (1 << I2C_MASTER_EVENT_RX_COMPLETE)) != 0), FSP_ERR_ABORTED );

    ret = FSP_SUCCESS;

    return ret;
}

void sci_i2c_master_callback(i2c_master_callback_args_t *p_args)
{
    BaseType_t pxHigherPriorityTaskWoken;

    xEventGroupSetBitsFromISR( i2c_sci0_event_handle,
                               (1 << p_args->event),
                               &pxHigherPriorityTaskWoken );


    switch(p_args->event)
    {
        case I2C_MASTER_EVENT_RX_COMPLETE:
            i2c_cnt_rx_complete++;
            break;
        case I2C_MASTER_EVENT_TX_COMPLETE:
            i2c_cnt_tx_complete++;
            break;
        case I2C_MASTER_EVENT_ABORTED:
            i2c_cnt_com_error++;
            break;
        default:
            break;
    }
}

void riic_i2c_master_callback(i2c_master_callback_args_t *p_args)
{
    BaseType_t pxHigherPriorityTaskWoken;

    xEventGroupSetBitsFromISR( i2c_riic0_event_handle,
                               (1 << p_args->event),
                               &pxHigherPriorityTaskWoken );


    switch(p_args->event)
    {
        case I2C_MASTER_EVENT_RX_COMPLETE:
            i2c_cnt_rx_complete++;
            break;
        case I2C_MASTER_EVENT_TX_COMPLETE:
            i2c_cnt_tx_complete++;
            break;
        case I2C_MASTER_EVENT_ABORTED:
            i2c_cnt_com_error++;
            break;
        default:
            break;
    }
}

/***********************************************************************************************************************
 * Private Functions Definitions
 **********************************************************************************************************************/

/*Clear the selected buffer*/
static bool i2c_mst_clear_buffer_n(uint8_t* buff_p, size_t n)
{
    bool ret = false;

    ret = (buff_p != NULL);

    if(ret)
    {
        for(size_t i = 0; i < n; i++)
        {
            buff_p[i] = 0x00;
        }
    }

    return ret;
}
