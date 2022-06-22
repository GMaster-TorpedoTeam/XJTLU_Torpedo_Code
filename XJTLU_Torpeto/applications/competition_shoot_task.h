#ifndef OLED_TASK_H
#define OLED_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"
#include "remote_control.h"

#define shoot_speed 8000

extern RC_ctrl_t rc_ctrl;
extern uint8_t adjust_flag;

extern void c_shoot_task(void const * argument);


#endif
