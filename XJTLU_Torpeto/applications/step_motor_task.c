#include "step_motor_task.h"
#include "main.h"

extern RC_ctrl_t rc_ctrl;
extern TIM_HandleTypeDef htim1;

void rc2StepMotor(TIM_TypeDef* TIMx)
{
	int temp;
	uint32_t fre;
	
	temp = rc_ctrl.rc.ch[1];
	if(temp >= 50)
	{
		fre = 35000/temp;
		TIM_Freq_Set(motor_yaw_TIM, fre);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	}
	else if(temp <= -50)
	{
		fre = -35000/temp;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
		TIM_Freq_Set(motor_yaw_TIM, fre);
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	}
	else
	{
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_2);
	}
}
