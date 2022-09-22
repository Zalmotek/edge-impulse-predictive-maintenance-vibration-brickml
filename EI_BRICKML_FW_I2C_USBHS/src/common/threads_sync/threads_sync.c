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
 * File Name    : threads_sync.c
 * Description  : This module contains a class used to synchronized the boot sequence of a multi-thread system.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "FreeRTOS.h"
#include "common_assert.h"
#include "event_groups.h"
#include "threads_sync_own.h"
#include "threads_sync_use.h"

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
static ThreadsSync_t local_this;
static ThreadsSync_t* this_ = &local_this;

/***********************************************************************************************************************
 * Public API Functions Definitions
 **********************************************************************************************************************/
fsp_err_t ThreadsSync_Open( void )
{
    this_->event_handle = xEventGroupCreateStatic( &this_->event_buf );
    return FSP_SUCCESS;
}


fsp_err_t ThreadsSync_Close( void )
{
    vEventGroupDelete( this_->event_handle );
    return FSP_SUCCESS;
}


fsp_err_t ThreadsSync_SetEvent( uint32_t flags_to_set )
{
    xEventGroupSetBits( this_->event_handle, flags_to_set );
    return FSP_SUCCESS;
}

fsp_err_t ThreadsSync_wait( uint32_t requested_flags,
                            uint32_t timeout_ticks )
{
    EventBits_t actual_flags;
    actual_flags = xEventGroupWaitBits( this_->event_handle,
                                        requested_flags,
                                        pdFALSE,
                                        pdTRUE,
                                        timeout_ticks );
    
    return ((actual_flags & requested_flags) == requested_flags) ? FSP_SUCCESS : FSP_ERR_TIMEOUT;
}
