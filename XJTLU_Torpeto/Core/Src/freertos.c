/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "shoot_speed_control.h"
#include "mode_task.h"
#include "OLED_task.h"
#include "referee_usart_task.h"
#include "referee_send_task.h"
#include "StepMotor_position_reset_task.h"
#include "competition_mode_task.h"
#include "choose_torpedo_task.h"
#include "position_adjust_task.h"
#include "competition_shoot_task.h"
#include "competion_step_motor_task.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

extern void oled_show_task(void const * argument);
extern void mode_choose_task(void const * argument);
extern void c_shoot_task(void const * argument);

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

osThreadId shootTaskHandle;
osThreadId modeTaskHandle;
osThreadId OLEDTaskHandle;
osThreadId RefereeSendTaskHandle;
osThreadId PositionResetTaskHandle;
osThreadId CompetitionTaskHandle;
osThreadId chooseTorpedoTaskHandle;
osThreadId PositionAdjustTaskHandle;
osThreadId CompetitionShootTaskHandle;
osThreadId C_StepShootTaskHandle;

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	
	/* definition and creation of shootTask*/
  osThreadDef(shootTask, shoot_speed_task, osPriorityHigh, 0, 512);
  shootTaskHandle = osThreadCreate(osThread(shootTask), NULL);
	
	/* definition and creation of modeTask*/
  osThreadDef(modeTask, mode_choose_task, osPriorityLow, 0, 512);
  modeTaskHandle = osThreadCreate(osThread(modeTask), NULL);
	
	/* definition and creation of shootTask*/
  osThreadDef(OLEDTask, oled_show_task, osPriorityNormal, 0, 256);
  OLEDTaskHandle = osThreadCreate(osThread(OLEDTask), NULL);
	
	osThreadDef(usartTask, referee_usart_task, osPriorityBelowNormal, 0, 256);
  OLEDTaskHandle = osThreadCreate(osThread(usartTask), NULL);
	
	osThreadDef(RefereeSendTask, referee_send_task, osPriorityNormal, 0, 512);
  RefereeSendTaskHandle = osThreadCreate(osThread(RefereeSendTask), NULL);
	
	osThreadDef(PositionResetTask, step_motor_reset_task, osPriorityNormal, 0, 128);
  PositionResetTaskHandle = osThreadCreate(osThread(PositionResetTask), NULL);
	
	osThreadDef(CompetitionTask, competition_mode_task, osPriorityNormal, 0, 128);
  CompetitionTaskHandle = osThreadCreate(osThread(CompetitionTask), NULL);
	
	osThreadDef(chooseTorpedoTask, choose_task, osPriorityNormal, 0, 128);
  chooseTorpedoTaskHandle = osThreadCreate(osThread(chooseTorpedoTask), NULL);
	
	osThreadDef(PositionAdjustTask, adjust_task, osPriorityNormal, 0, 128);
  PositionAdjustTaskHandle = osThreadCreate(osThread(PositionAdjustTask), NULL);
	
	osThreadDef(CompetitionShootTask, c_shoot_task, osPriorityNormal, 0, 128);
  CompetitionShootTaskHandle = osThreadCreate(osThread(CompetitionShootTask), NULL);
	
	osThreadDef(C_StepShootTask, c_step_task, osPriorityAboveNormal, 0, 256);
  C_StepShootTaskHandle = osThreadCreate(osThread(C_StepShootTask), NULL);
	
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
