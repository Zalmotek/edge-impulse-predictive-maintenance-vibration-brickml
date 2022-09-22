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
 * File Name    : threads_sync_own.h
 * Description  : This module contains the build API declaration of the class threads_sync.
 **********************************************************************************************************************/
#ifndef THREADS_SYNC_OWN_H
#define THREADS_SYNC_OWN_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "threads_sync.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
struct ThreadsSync_
{
    EventGroupHandle_t event_handle;
    StaticEventGroup_t event_buf;
#ifndef SKIP_INTEGRITY_CHECK
    ThreadsSync_t* self;
#endif
};

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * @brief   Create a new threads synchronization module
 *
 * This function create and configure a thread synchronization module that can be used to force as exact threads
 * initialization sequence. This module is a singleton.
  *********************************************************************************************************************/
fsp_err_t ThreadsSync_Open( void );

/***********************************************************************************************************************
 * @brief   Delete the Thread synchronization module
 *
 * This function delete a previously created threads synchronization module.
  *********************************************************************************************************************/
fsp_err_t ThreadsSync_Close( void );

#endif
