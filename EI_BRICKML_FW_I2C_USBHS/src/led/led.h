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
 * File Name: led.h
 * Version : 1.0
 * Description : This header file defines the LED basic driver.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 17.10.2020 1.00 First Release
 ***********************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "stdbool.h"
#include "stddef.h"
#include "r_ioport.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/
#define INVALID_LED_PIN       (0xFFFF)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum Led_colour
{
    COLOUR_NONE= 0,
    COLOUR_BLUE,
    COLOUR_RED,
    COLOUR_PURPLE,
    //
    COLOUR_NUM
} Led_colour_t;

typedef struct Led_cfg_
{
    ioport_port_pin_t pin;
    bsp_io_level_t activeState;
} Led_cfg_t;

typedef struct Led_
{
    Led_cfg_t red;
    Led_cfg_t blue;
} Led_t;

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/
void LED_build( Led_t* led_p,
                ioport_port_pin_t redPin, bsp_io_level_t redActiveState,
                ioport_port_pin_t bluePin, bsp_io_level_t blueActiveState );

void LED_destroy( Led_t* led_p );

void LED_setColour( Led_t* led_p, Led_colour_t colourToSet );

#endif /* LED_H_ */
