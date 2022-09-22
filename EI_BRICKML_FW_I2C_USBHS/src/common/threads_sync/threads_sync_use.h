/***********************************************************************************************************************
 * Copyright [2020] RELOC s.r.l. - All rights strictly reserved
 * This Software is provided for evaluation purposes; any other use - including reproduction, modification, use for
 * a commercial product, distribution, or republication - without the prior written permission of the Copyright holder
 * is strictly prohibited. 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : threads_sync_use.h
 * Description  : This module contains the usage API declaration of the class threads_sync.
 **********************************************************************************************************************/
#ifndef THREADS_SYNC_USE_H
#define THREADS_SYNC_USE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdint.h>
#include "threads_sync.h"
#include "threads_sync_events.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * @brief   Set a new event
 *
 * Set a new event. If some threads is waiting for this event it will be resumed.
 * 
 * @param[in] flags_to_set              Flag to set (choosing from the threads_sync_events.h file).
 
 * @retval RET_SUCCESS                  Event successfully added.
 * @retval RET_FAIL                     Error setting the event.
  *********************************************************************************************************************/
fsp_err_t ThreadsSync_SetEvent( uint32_t flags_to_set );

/***********************************************************************************************************************
 * @brief   Wait for a configurable event set.
 *
 * Suspend the calling thread until the requested events will be triggered or if the timeout time is reached.
 * 
 * @param[in] requested_flags           Flag to wait (choosing from the threads_sync_events.h file).
 * @param[in] timeout                   The time to wait for the events to become available, in ticks unit.
 *                                      OS_NO_WAIT = 0 timeout.
 *                                      OS_WAIT_FOREVER = waits indefinitely.
 *
 * @retval RET_SUCCESS                  Event successfully found.
 * @retval RET_TIMEOUT                  Timeout occurred before the events become available.
 * @retval RET_FAIL                     Event wait failed.
  *********************************************************************************************************************/
fsp_err_t ThreadsSync_wait( uint32_t requested_flags,
                            uint32_t timeout_ticks );

#endif
