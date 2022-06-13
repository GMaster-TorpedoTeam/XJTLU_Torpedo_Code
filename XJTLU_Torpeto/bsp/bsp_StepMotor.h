#ifndef BSP_STEPMOTOR_H
#define BSP_STEPMOTOR_H

#include "stm32f4xx_hal.h"
#include "remote_control.h"
#include "struct_typedef.h"

#define motor_yaw_GPIO GPIOE
#define motor_yaw_PIN GPIO_PIN_11
#define motor_yaw_TIM TIM1
#define motor_yaw_CHANNAL TIM_CHANNEL_2

#define motor_pitch_GPIO GPIOC
#define motor_pitch_PIN GPIO_PIN_6
#define motor_pitch_TIM TIM8
#define motor_pitch_CHANNAL TIM_CHANNEL_1

void TIM_Freq_Set(TIM_TypeDef* TIMx, uint32_t Freq);


#endif
