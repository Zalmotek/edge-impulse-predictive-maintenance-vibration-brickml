/***********************************************************************************************************************
 * Copyright [2020] RELOC s.r.l. - All rights strictly reserved
 * This Software is provided for evaluation purposes; any other use — including reproduction, modification, use for
 * a commercial product, distribution, or republication — without the prior written permission of the Copyright holder
 * is strictly prohibited.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * File Name        : threads_sync_events.h
 * Description      : Threads sync events header file
 *********************************************************************************************************************/
#ifndef THREADS_SYNC_EVENTS_H
#define THREADS_SYNC_EVENTS_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

#define THREADS_SYNC_RDY_BLE                ( 1 << 0 )
#define THREADS_SYNC_RDY_MAIN               ( 1 << 1 )
#define THREADS_SYNC_RDY_I2C_INIT           ( 1 << 2 )
#define THREADS_SYNC_RDY_I2C_RUN_COMP       ( 1 << 3 )

/*#define THREADS_SYNC_RDY_ALL                ( THREADS_SYNC_RDY_BLE | \
                                              THREADS_SYNC_RDY_MAIN| \
                                              THREADS_SYNC_RDY_I2C_INIT) | \
                                              THREADS_SYNC_RDY_I2C_RUN_COMP
                                              */

#endif  /* THREADS_SYNC_EVENTS_H */

