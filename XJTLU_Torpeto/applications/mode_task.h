#ifndef USER_PID_H
#define USER_PID_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "remote_control.h"
#include "shoot_speed_control.h"
#include "step_motor_task.h"
#include "user_pid.h"

extern RC_ctrl_t rc_ctrl;
extern fp32 shoot_speed_set;
extern fp32 push_speed_set;
extern void user_pid_Calc(void);

void mode_choose(void);

extern void mode_choose_task(void const * argument);

#endif
