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
 * File Name        : main_thread_entry.c
 * Description      : Main thread.
 *********************************************************************************************************************/

#define MODULE_NAME "main_thread_entry"

#include <main_thread.h>
#include "common_assert.h"
#include "trace_own.h"
#include "trace_use.h"
#include "version.h"
#include "threads_sync_use.h"
#include "main_thread_entry.h"
#include "comms/comms.h"
#include "config.h"
#include "led_action.h"
#include "led.h"
#include "task.h"
#include <stdio.h>
#include <string.h>
/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * Private variables
 **********************************************************************************************************************/

uint8_t     g_str[100] = {0};
uint32_t    g_len = 0;

#define USB_BUFFER_SIZE (100) //(2*1024) //(100) ////
uint8_t usb_buff_try_counter = 0;
//const uint8_t     g_const_str[50] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
const uint8_t     g_const_str[1024] = {"abc"};

void pin_toggle(void);
void led_toggle(void);
void button_init(void);

/***********************************************************************************************************************
 * Public API Functions Definitions
 **********************************************************************************************************************/

/* Main Thread entry function */
/* pvParameters contains TaskHandle_t */
void main_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    fsp_err_t err;
    uint32_t last_counter = 0;
    uint32_t counter = 0;
    uint32_t tick = 0;

    led_toggle();
    button_init();

    Trace_build( &g_uart_trace );
    TRACE( (char*) Version_getInfoStr( NULL ) );

#if 1
    /* Open the comms driver */
    err = comms_open();
    if (FSP_SUCCESS != err)
    {
        /* Stop as comms close failure */
        __BKPT(1);
    }
#endif
    vTaskDelay (1000);
    tick = xTaskGetTickCount();

    sprintf((char *)g_str, "USB send and receive using FreeRTOS working.\r\n");
    comms_send(g_str, strlen((char *)g_str), 0);

    TRACE( (char*) Version_getInfoStr( NULL ) );

    led_toggle();

    // simple console
#if 1
    g_str[0] = 0;
    while (1)
    {
        g_len = 1;
        err = comms_read(g_str, &g_len, portMAX_DELAY);
        if (FSP_SUCCESS != err)
        {
            //__BKPT(1);
        }
        else
        {
            err = comms_send(g_str, g_len, 100);
            if (err == FSP_SUCCESS)
            {

            }
        }
    }
#endif
    while (1)
    {
        vTaskDelay (portMAX_DELAY);
    }
}


