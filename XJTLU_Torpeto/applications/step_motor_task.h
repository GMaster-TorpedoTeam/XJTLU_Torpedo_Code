#ifndef STEP_MOTOR_TASK_H
#define STEP_MOTOR_TASK_H

#include "stm32f4xx_hal.h"
#include "remote_control.h"
#include "struct_typedef.h"

#include "bsp_StepMotor.h"

void rc2StepMotor(TIM_TypeDef* TIMx);

#endif
