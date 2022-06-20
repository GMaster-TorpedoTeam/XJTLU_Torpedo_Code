#ifndef COMPETITION_MODE_TASK_H
#define COMPETITION_MODE_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"
#include "remote_control.h"
#include "user_pid.h"
#include "stdlib.h"

#define StepMotor_Move_round 70

extern RC_ctrl_t rc_ctrl;
extern pid_type_def C_PushMotor_GYRO;
extern pid_type_def C_PushMotor_SPEED;

extern void competition_mode_task(void const * argument);

void Move_Step_Motor(void);

#endif
