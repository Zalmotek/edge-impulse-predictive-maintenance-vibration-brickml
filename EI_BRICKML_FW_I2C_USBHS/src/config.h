/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2019-2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name: config.h
 * Version : 1.0
 * Description : This header file defines the Advertising Mode type used in the firmware
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 12.10.2020 1.00 First Release
 ***********************************************************************************************************************/


#ifndef CONFIG_H_
#define CONFIG_H_

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/
#define BLE_ADV_INTERVAL_DEFAULT_MS                 500
#define BLE_ADV_MODE_DEFAULT                        ADV_MODE_BLE4

#define SW3_PIN                                     BSP_IO_PORT_01_PIN_06


/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum {
    ADV_MODE_BLE4=0,
    ADV_MODE_BLE5,
    ADV_MODE_BLE5_LR,
    ADV_MODE_BLE_MAX,
} adv_mode_t;


typedef enum {
    IDENTIFY_OFF=0,
    IDENTIFY_ON,
    IDENTIFY_NIGHT_MODE,
    IDENTIFY_MAX,
} identify_t;

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/

#endif /* CONFIG_H_ */
