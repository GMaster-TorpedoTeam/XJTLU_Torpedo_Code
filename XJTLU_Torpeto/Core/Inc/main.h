/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define push_low_Pin GPIO_PIN_7
#define push_low_GPIO_Port GPIOI
#define push_high_Pin GPIO_PIN_6
#define push_high_GPIO_Port GPIOI
#define Laser_Pin GPIO_PIN_8
#define Laser_GPIO_Port GPIOC
#define StepMotor2_pluse_signal_Pin GPIO_PIN_6
#define StepMotor2_pluse_signal_GPIO_Port GPIOC
#define StepMotro1_Dir_Pin GPIO_PIN_13
#define StepMotro1_Dir_GPIO_Port GPIOE
#define StepMotor1_pluse_signal_Pin GPIO_PIN_11
#define StepMotor1_pluse_signal_GPIO_Port GPIOE
#define StepMotro2_Dir_Pin GPIO_PIN_14
#define StepMotro2_Dir_GPIO_Port GPIOE
#define yaw_right_Pin GPIO_PIN_12
#define yaw_right_GPIO_Port GPIOB
#define yaw_left_Pin GPIO_PIN_13
#define yaw_left_GPIO_Port GPIOB
#define pitch_front_Pin GPIO_PIN_14
#define pitch_front_GPIO_Port GPIOB
#define pitch_back_Pin GPIO_PIN_15
#define pitch_back_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
