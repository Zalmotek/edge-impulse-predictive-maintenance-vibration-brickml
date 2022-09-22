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
 * Description  : This module defines the LED action driver.
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 12.10.2020 1.00     First Release
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "led_action.h"
#include "common_data.h"
#include "common_assert.h"

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

/***********************************************************************************************************************
 * Public API Functions Definitions
 **********************************************************************************************************************/
void LED_ACTION_build( LedAction_t* led_act_p, Led_t* led_p )
{
    if ( (led_act_p != NULL) && (led_p != NULL) )
    {
        led_act_p->led_p = led_p;
        LED_setColour( led_act_p->led_p, COLOUR_NONE );
        led_act_p->current_state = STATE_IDLE;
        led_act_p->absolute_time_ms = 0;
    }
}

void LED_ACTION_destroy( LedAction_t* led_act_p )
{
    if (led_act_p != NULL)
    {
        led_act_p->led_p = NULL;
        led_act_p->current_state = STATE_IDLE;
    }
}

void LED_ACTION_turnOn( LedAction_t* led_act_p, Led_colour_t colourToSet )
{
    if (led_act_p != NULL)
    {
        LED_setColour( led_act_p->led_p, colourToSet );
        led_act_p->current_state = STATE_IDLE;
    }
}

void LED_ACTION_turnOff( LedAction_t* led_act_p )
{
    if (led_act_p != NULL)
    {
        LED_setColour( led_act_p->led_p, COLOUR_NONE );
        led_act_p->current_state = STATE_IDLE;
    }
}

void LED_ACTION_blink( LedAction_t* led_act_p, uint32_t period_ms, uint8_t duty_cycle, Led_colour_t colourToSet )
{
    if (led_act_p != NULL)
    {
        led_act_p->colour = colourToSet;
        LED_setColour( led_act_p->led_p, colourToSet );
        led_act_p->current_state = STATE_BLINKY_ON;
        led_act_p->absolute_time_ms = 0;
        led_act_p->next_step_absolute_time_ms = ((led_act_p->period_ms*led_act_p->duty_cycle)/100);
        led_act_p->period_ms = period_ms;
        led_act_p->duty_cycle = duty_cycle;
    }
}

void LED_ACTION_blinkN( LedAction_t* led_act_p, uint32_t period_ms, uint8_t duty_cycle, Led_colour_t colourToSet, uint32_t blink_num )
{
    if ((led_act_p != NULL) && (blink_num > 0))
    {
        led_act_p->colour = colourToSet;
        LED_setColour( led_act_p->led_p, colourToSet );
        led_act_p->current_state = STATE_BLINK_N_ON;
        led_act_p->absolute_time_ms = 0;
        led_act_p->next_step_absolute_time_ms = ((((led_act_p->blink_counter*2) + 1)*led_act_p->period_ms*led_act_p->duty_cycle)/100);
        led_act_p->blink_num = blink_num;
        led_act_p->blink_counter = 0;
        led_act_p->period_ms = period_ms;
        led_act_p->duty_cycle = duty_cycle;
    }
}

uint32_t LED_ACTION_run( LedAction_t* led_act_p, uint32_t msElapsedTime )
{
    uint32_t next_delay_ms;
    if( led_act_p != NULL )
    {
        switch ( led_act_p->current_state )
        {
            case STATE_IDLE:
                led_act_p->absolute_time_ms = 0;
                led_act_p->next_step_absolute_time_ms = 0xFFFFFFFF;
                break;
            case STATE_BLINKY_ON:
                led_act_p->absolute_time_ms += msElapsedTime;
                if( led_act_p->absolute_time_ms >= led_act_p->next_step_absolute_time_ms )
                {
                    LED_setColour( led_act_p->led_p, COLOUR_NONE );
                    led_act_p->current_state = STATE_BLINKY_OFF;
                    led_act_p->next_step_absolute_time_ms = led_act_p->period_ms;
                }
                break;
            case STATE_BLINKY_OFF:
                led_act_p->absolute_time_ms += msElapsedTime;
                if( led_act_p->absolute_time_ms >= led_act_p->next_step_absolute_time_ms )
                {
                    LED_setColour( led_act_p->led_p, led_act_p->colour );
                    led_act_p->absolute_time_ms = 0;
                    led_act_p->current_state = STATE_BLINKY_ON;
                    led_act_p->next_step_absolute_time_ms = ((led_act_p->period_ms*led_act_p->duty_cycle)/100);
                }
                break;
            case STATE_BLINK_N_ON:
                led_act_p->absolute_time_ms += msElapsedTime;
                if( led_act_p->absolute_time_ms >= led_act_p->next_step_absolute_time_ms )
                {
                    LED_setColour( led_act_p->led_p, COLOUR_NONE );
                    led_act_p->blink_counter++;
                    if( led_act_p->blink_counter == led_act_p->blink_num )
                    {
                        led_act_p->current_state = STATE_BLINK_N_OFF_RESIDUAL;
                        led_act_p->next_step_absolute_time_ms = led_act_p->period_ms;
                    }
                    else
                    {
                        led_act_p->current_state = STATE_BLINK_N_OFF;
                        led_act_p->next_step_absolute_time_ms = ((led_act_p->blink_counter*2*led_act_p->period_ms*led_act_p->duty_cycle)/100);
                    }
                }
                break;
            case STATE_BLINK_N_OFF:
                led_act_p->absolute_time_ms += msElapsedTime;
                if( led_act_p->absolute_time_ms >= led_act_p->next_step_absolute_time_ms )
                {
                    LED_setColour( led_act_p->led_p, led_act_p->colour );
                    led_act_p->current_state = STATE_BLINK_N_ON;
                    led_act_p->next_step_absolute_time_ms = ((((led_act_p->blink_counter*2) + 1)*led_act_p->period_ms*led_act_p->duty_cycle)/100);
                }
                break;
            case STATE_BLINK_N_OFF_RESIDUAL:
                led_act_p->absolute_time_ms += msElapsedTime;
                if( led_act_p->absolute_time_ms >= led_act_p->next_step_absolute_time_ms )
                {
                    LED_setColour( led_act_p->led_p, led_act_p->colour );
                    led_act_p->absolute_time_ms = 0;
                    led_act_p->blink_counter = 0;
                    led_act_p->current_state = STATE_BLINK_N_ON;
                    led_act_p->next_step_absolute_time_ms = ((((led_act_p->blink_counter*2) + 1)*led_act_p->period_ms*led_act_p->duty_cycle)/100);
                }
                break;
            default:
                break;
        }
    }
    
    if(led_act_p->next_step_absolute_time_ms > led_act_p->absolute_time_ms)
    {
        next_delay_ms = (led_act_p->next_step_absolute_time_ms - led_act_p->absolute_time_ms);
    }
    else
    {
        /* Next step time behind current time! Force re-alignment */
        next_delay_ms = 0;
        led_act_p->absolute_time_ms = led_act_p->next_step_absolute_time_ms;
    }
    
    return next_delay_ms;
}



