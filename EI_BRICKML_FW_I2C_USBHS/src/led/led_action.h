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
 * Description : This header file defines the LED action driver.
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 17.10.2020 1.00 First Release
 ***********************************************************************************************************************/
#ifndef LED_ACTION_H_
#define LED_ACTION_H_

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "led.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum LedAction_state_
{
    STATE_IDLE = 0,
    STATE_BLINKY_ON,
    STATE_BLINKY_OFF,
    STATE_BLINK_N_ON,
    STATE_BLINK_N_OFF,
    STATE_BLINK_N_OFF_RESIDUAL,
    /* --- */
    STATE_NUM
} LedAction_state_t;

typedef struct LedAction_ LedAction_t;

struct LedAction_
{
    Led_t* led_p;
    LedAction_state_t current_state;            // current blink state
    uint32_t period_ms;                         // blink ms period required
    uint8_t duty_cycle;                         // blink duty cycle required
    Led_colour_t colour;                        // led colour
    uint32_t absolute_time_ms;                  // current time elapsed
    uint32_t blink_num;                         // number of remaining blinks
    uint32_t blink_counter;                     // current blink counter
    uint32_t next_step_absolute_time_ms;
};

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/
void LED_ACTION_build( LedAction_t* led_act_p, Led_t* Led_p );
void LED_ACTION_destroy( LedAction_t* led_act_p );

void LED_ACTION_turnOn( LedAction_t* led_act_p, Led_colour_t colourToSet );
void LED_ACTION_turnOff( LedAction_t* led_act_p );

void LED_ACTION_blink( LedAction_t* led_act_p, uint32_t period_ms, uint8_t duty_cycle, Led_colour_t colourToSet );
void LED_ACTION_blinkN( LedAction_t* led_act_p, uint32_t period_ms, uint8_t duty_cycle, Led_colour_t colourToSet, uint32_t blink_num );
uint32_t LED_ACTION_run( LedAction_t* led_act_p, uint32_t msElapsedTime );


#endif /* LED_ACTION_H_ */
