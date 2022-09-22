/* generated common source file - do not edit */
#include "common_data.h"
icu_instance_ctrl_t g_external_irq9_ctrl;
const external_irq_cfg_t g_external_irq9_cfg =
{ .channel = 9,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = external_irq_button_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (15),
#if defined(VECTOR_NUMBER_ICU_IRQ9)
    .irq                 = VECTOR_NUMBER_ICU_IRQ9,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq9 =
{ .p_ctrl = &g_external_irq9_ctrl, .p_cfg = &g_external_irq9_cfg, .p_api = &g_external_irq_on_icu };
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
SemaphoreHandle_t g_usb_write_complete_binary_semaphore;
#if 1
StaticSemaphore_t g_usb_write_complete_binary_semaphore_memory;
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);
QueueHandle_t g_usb_read_queue;
#if 1
StaticQueue_t g_usb_read_queue_memory;
uint8_t g_usb_read_queue_queue_memory[4 * 20];
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void)
{
    g_usb_write_complete_binary_semaphore =
#if 1
            xSemaphoreCreateBinaryStatic (&g_usb_write_complete_binary_semaphore_memory);
#else
                xSemaphoreCreateBinary();
                #endif
    if (NULL == g_usb_write_complete_binary_semaphore)
    {
        rtos_startup_err_callback (g_usb_write_complete_binary_semaphore, 0);
    }
    g_usb_read_queue =
#if 1
            xQueueCreateStatic (
#else
                xQueueCreate(
                #endif
                                20,
                                4
#if 1
                                ,
                                &g_usb_read_queue_queue_memory[0], &g_usb_read_queue_memory
#endif
                                );
    if (NULL == g_usb_read_queue)
    {
        rtos_startup_err_callback (g_usb_read_queue, 0);
    }
}
