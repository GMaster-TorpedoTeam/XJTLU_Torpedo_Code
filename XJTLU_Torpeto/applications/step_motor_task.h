#ifndef STEP_MOTOR_TASK_H
#define STEP_MOTOR_TASK_H

#include "stm32f4xx_hal.h"
#include "remote_control.h"
#include "struct_typedef.h"

#include "bsp_StepMotor.h"

#define Set_Fre 150
#define RC_DeadZone 30
#define pulse_step 50


extern RC_ctrl_t rc_ctrl;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;

extern uint8_t yaw_PWM_flag;
extern uint8_t pitch_PWM_flag;

void rc2StepMotor(TIM_TypeDef* TIMx);
void PWM_Pulse_Control(TIM_TypeDef* TIMx, uint16_t yaw_step, uint16_t pitch_step);

#endif
