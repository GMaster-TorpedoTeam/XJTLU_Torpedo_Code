#ifndef BSP_COMPETITION_MODE_H
#define BSP_COMPETITION_MODE_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "user_pid.h"

extern pid_type_def C_PushMotor_GYRO;
extern pid_type_def C_PushMotor_SPEED;

extern fp32 C_set_step_motor;
extern uint8_t c_shoot_report;

void Move_Step_Motor(int round);

#endif
