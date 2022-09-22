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
 * File Name    : led.c
 * Version      : 1.00
 * Description  : This module defines the LED basic driver.
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 12.10.2020 1.00     First Release
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "led.h"
#include "common_data.h"
#include "common_assert.h"


/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct colourAffinity_
{
    bool red;
    bool blue;
} Led_colourAffinity_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables
 **********************************************************************************************************************/
static const Led_colourAffinity_t colourAffinity[COLOUR_NUM] = { {0,0},
                                                                 {0,1},
                                                                 {1,0},
                                                                 {1,1} };

/***********************************************************************************************************************
 * Public API Functions Definitions
 **********************************************************************************************************************/
void LED_build( Led_t* led_p,
                ioport_port_pin_t redPin, bsp_io_level_t redActiveState,
                ioport_port_pin_t bluePin, bsp_io_level_t blueActiveState )
{
    if (led_p != NULL)
    {
        led_p->red.pin = redPin;
        led_p->red.activeState = redActiveState;
        led_p->blue.pin = bluePin;
        led_p->blue.activeState = blueActiveState;
    }
}

void LED_destroy( Led_t* led_p )
{
    if (led_p != NULL)
    {
        led_p->red.pin = INVALID_LED_PIN;
        led_p->blue.pin = INVALID_LED_PIN;
    }
}

void LED_setColour( Led_t* led_p, Led_colour_t colourToSet )
{
    if( (led_p != NULL) && (colourToSet < COLOUR_NUM))
    {
        bsp_io_level_t inactiveState;
        if( led_p->red.pin != INVALID_LED_PIN )
        {
            inactiveState = (led_p->red.activeState == BSP_IO_LEVEL_LOW) ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;
            ASSERT( g_ioport.p_api->pinWrite( g_ioport.p_ctrl, led_p->red.pin, (colourAffinity[colourToSet].red == 1)?led_p->red.activeState: inactiveState  ) == FSP_SUCCESS);
        }
        
        if( led_p->blue.pin != INVALID_LED_PIN )
        {
            inactiveState = (led_p->blue.activeState == BSP_IO_LEVEL_LOW) ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;
            ASSERT( g_ioport.p_api->pinWrite( g_ioport.p_ctrl, led_p->blue.pin, (colourAffinity[colourToSet].blue == 1)?led_p->blue.activeState: inactiveState  ) == FSP_SUCCESS);
        }
    }
}
