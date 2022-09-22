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
 * File Name: i2c_mst_thread_entry
 * Version : 1.0
 * Description : The header file for I2C MST thread entry
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 12.10.2020 1.00 First Release
 ***********************************************************************************************************************/

#ifndef SENSORS_THREAD_ENTRY_H_
#define SENSORS_THREAD_ENTRY_H_

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public API Function Declarations
 **********************************************************************************************************************/

/***************************************************************************//**
 * @brief     Transmit the data on the I2C Bus
 *
 * @param[in] buf      Address of the buffer that contains the data that have to be transmitted
 * @param[in] len      Buffer length
 * @param[in] restart  If true a restart condition is transmitted (required to read a register)
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_write( uint8_t* buf, uint32_t buf_len, bool restart );

/***************************************************************************//**
 * @brief     Receive data from the I2C Bus
 *
 * @param[in] buf      Reception Buffer Address
 * @param[in] len      Buffer length
 * @param[in] restart  If true a restart condition is transmitted
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_read( uint8_t* buf, uint32_t buf_len, bool restart );

/***************************************************************************//**
 * @brief     Read a Register Value (8-bit address) from the I2C Bus
 *
 * @param[in] reg_addr Register Address
 * @param[in] buf      Reception Buffer Address
 * @param[in] len      Buffer length
 *
 * @return    @ref fsp_err_t
*******************************************************************************/

fsp_err_t i2c_mst_read_register(uint8_t reg_addr, uint8_t* buf, uint32_t buf_len);

/***************************************************************************//**
 * @brief     Initialize the I2C communication
*******************************************************************************/

fsp_err_t i2c_mst_init_communication(void);

/***************************************************************************//**
 * @brief     Check if the task is sleeping and the MCU can enter Low Power Modes
*******************************************************************************/

bool i2c_mst_is_idle( void );

#endif /* SENSORS_THREAD_ENTRY_H_ */
