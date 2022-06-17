#ifndef STEP_MOTOR_TASK_H
#define STEP_MOTOR_TASK_H

#include "stm32f4xx_hal.h"
#include "remote_control.h"
#include "struct_typedef.h"

#include "bsp_StepMotor.h"

extern RC_ctrl_t rc_ctrl;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;

void rc2StepMotor(TIM_TypeDef* TIMx);

#endif
