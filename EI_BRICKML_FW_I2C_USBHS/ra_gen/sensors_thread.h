/* generated thread header file - do not edit */
#ifndef SENSORS_THREAD_H_
#define SENSORS_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void sensors_thread_entry(void * pvParameters);
                #else
extern void sensors_thread_entry(void *pvParameters);
#endif
#include "r_iic_master.h"
#include "r_i2c_master_api.h"
#include "r_sci_i2c.h"
#include "r_i2c_master_api.h"
FSP_HEADER
/* I2C Master on IIC Instance. */
extern const i2c_master_instance_t g_i2c_master0;

/** Access the I2C Master instance using these structures when calling API functions directly (::p_api is not used). */
extern iic_master_instance_ctrl_t g_i2c_master0_ctrl;
extern const i2c_master_cfg_t g_i2c_master0_cfg;

#ifndef riic_i2c_master_callback
void riic_i2c_master_callback(i2c_master_callback_args_t *p_args);
#endif
extern const i2c_master_cfg_t g_i2c0_cfg;
/* I2C on SCI Instance. */
extern const i2c_master_instance_t g_i2c0;
#ifndef sci_i2c_master_callback
void sci_i2c_master_callback(i2c_master_callback_args_t *p_args);
#endif

extern const sci_i2c_extended_cfg_t g_i2c0_cfg_extend;
extern sci_i2c_instance_ctrl_t g_i2c0_ctrl;
FSP_FOOTER
#endif /* SENSORS_THREAD_H_ */
