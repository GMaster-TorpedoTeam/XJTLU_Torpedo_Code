#include "step_motor_task.h"


void rc2StepMotor(TIM_TypeDef* TIMx)
{
	uint32_t fre;
	
	if (TIMx == motor_yaw_TIM)
	{
		
		if(rc_ctrl.rc.ch[2] >= 50 )
			{
				fre = 50;
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, GPIO_PIN_SET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				
			}
		else if(rc_ctrl.rc.ch[2] <= -50 )
			{
				fre = 50;
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, GPIO_PIN_RESET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
			}
		else
			{
				HAL_TIM_PWM_Stop(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
			}
		
	}
	else if (TIMx == motor_pitch_TIM)
	{
		
		if(rc_ctrl.rc.ch[1] >= 50 )
			{
				fre = 50;
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, GPIO_PIN_RESET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
			}
		else if(rc_ctrl.rc.ch[1] <= -50)
			{
				fre = 50;
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, GPIO_PIN_SET);
				TIM_Freq_Set(motor_yaw_TIM, fre);
				HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
			}
		else
			{
				HAL_TIM_PWM_Stop(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
			}
	}
}

