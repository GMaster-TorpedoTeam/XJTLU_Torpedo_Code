#include "step_motor_task.h"
#include "main.h"

extern RC_ctrl_t rc_ctrl;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;


void rc2StepMotor(TIM_TypeDef* TIMx)
{
	int temp;
	uint32_t fre;
	
	if (TIMx == motor_yaw_TIM)
	{
		temp = rc_ctrl.rc.ch[2];
		
		if(temp >= 50 )
			{
				fre = 10000/temp;
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, GPIO_PIN_SET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				temp = 0;
			}
		else if(temp <= -50)
			{
				fre = -10000/temp;
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, GPIO_PIN_RESET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				temp = 0;
			}
		else
			{
				HAL_TIM_PWM_Stop(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				temp = 0;
			}
		
	}
	else if (TIMx == motor_pitch_TIM)
	{
		temp = rc_ctrl.rc.ch[1];
		
		if(temp >= 50 )
			{
				fre = 10000/temp;
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, GPIO_PIN_SET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
				temp = 0;
			}
		else if(temp <= -50)
			{
				fre = -10000/temp;
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, GPIO_PIN_RESET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
				temp = 0;
			}
		else
			{
				HAL_TIM_PWM_Stop(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
				temp = 0;
			}
	}
}

