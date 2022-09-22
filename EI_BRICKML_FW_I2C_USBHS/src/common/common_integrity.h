/***********************************************************************************************************************
 * Copyright [2019] RELOC s.r.l. - All rights strictly reserved
 * This Software is provided for evaluation purposes; any other use - including reproduction, modification, use for
 * a commercial product, distribution, or republication - without the prior written permission of the Copyright holder
 * is strictly prohibited. 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : common_integrity.h
 * Description  : This module contains the instance integrity macro definition.
 **********************************************************************************************************************/
#ifndef COMMON_INTEGRITY_H
#define COMMON_INTEGRITY_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "common_assert.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/
#ifndef SKIP_INTEGRITY_CHECK
#define INSTANCE_INTEGRITY_SET( this_ )     {                                       \
                                                ASSERT( this_ != NULL);             \
                                                this_->self = this_;                \
                                            }
                                            
#define INSTANCE_INTEGRITY_CHECK( this_ )   {                                       \
                                                ASSERT( this_ != NULL);             \
                                                ASSERT( this_->self == this_ );     \
                                            }

#define INSTANCE_INTEGRITY_DESTROY( this_ ) {                                       \
                                                ASSERT( this_ != NULL);             \
                                                this_->self = NULL;                 \
                                            }

#else

#define INSTANCE_INTEGRITY_SET( this_ )
#define INSTANCE_INTEGRITY_CHECK( this_ )
#define INSTANCE_INTEGRITY_DESTROY( this_ )

#endif

#endif
