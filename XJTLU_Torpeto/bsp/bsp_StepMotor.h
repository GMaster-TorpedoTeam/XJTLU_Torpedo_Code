#ifndef BSP_STEPMOTOR_H
#define BSP_STEPMOTOR_H

#include "stm32f4xx_hal.h"
#include "remote_control.h"
#include "struct_typedef.h"

///////////////////////////////////////////////////////

#define motor_yaw_TIM_Handle 	htim1
#define motor_yaw_TIM 				TIM1
#define motor_yaw_GPIO 				GPIOE
#define motor_yaw_PIN 				GPIO_PIN_11
#define motor_yaw_CHANNAL 		TIM_CHANNEL_2

#define motor_yaw_DIR_GPIO 		GPIOE
#define motor_yaw_DIR_PIN 		GPIO_PIN_13

///////////////////////////////////////////////////////

#define motor_pitch_TIM_Handle 	htim8
#define motor_pitch_TIM 				TIM8
#define motor_pitch_GPIO 				GPIOC
#define motor_pitch_PIN 				GPIO_PIN_6
#define motor_pitch_CHANNAL 		TIM_CHANNEL_1

#define motor_pitch_DIR_GPIO 		GPIOE
#define motor_pitch_DIR_PIN 		GPIO_PIN_14

////////////////////////////////////////////////////////限位引脚定义

#define pitch_front_GPIO 	GPIOB
#define pitch_front_PIN 	GPIO_PIN_14

#define pitch_back_GPIO 	GPIOB
#define pitch_back_PIN 		GPIO_PIN_15

#define yaw_left_GPIO 		GPIOB
#define yaw_left_PIN 			GPIO_PIN_13

#define yaw_right_GPIO 		GPIOB
#define yaw_right_PIN 		GPIO_PIN_12

////////////////////////////////////////////////////////读取限位状态

#define pitch_front_state HAL_GPIO_ReadPin(pitch_front_GPIO, pitch_front_PIN)
#define pitch_back_state 	HAL_GPIO_ReadPin(pitch_back_GPIO, pitch_back_PIN )
#define yaw_left_state 		HAL_GPIO_ReadPin(yaw_left_GPIO, yaw_left_PIN)
#define yaw_right_state 	HAL_GPIO_ReadPin(yaw_right_GPIO, yaw_right_PIN)

void TIM_Freq_Set(TIM_TypeDef* TIMx, uint32_t Freq);


#endif
