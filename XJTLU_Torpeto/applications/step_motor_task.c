#include "step_motor_task.h"

int yaw_position = 0;
int pitch_position = 0;

void rc2StepMotor(TIM_TypeDef* TIMx)
{
	
	if (TIMx == motor_yaw_TIM)
	{
		
		if(rc_ctrl.rc.ch[2] >= RC_DeadZone )
			{
				
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Right);
				//fre = Set_Fre;
				//TIM_Freq_Set(motor_yaw_TIM, fre);
				//HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
				
				
			}
		else if(rc_ctrl.rc.ch[2] <= -RC_DeadZone && yaw_limit_state != 1)
			{
				HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Left);
				//fre = Set_Fre;
				//TIM_Freq_Set(motor_yaw_TIM, fre);
				//HAL_TIM_PWM_Start(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
			}
		else
			{
				//HAL_TIM_PWM_Stop(&motor_yaw_TIM_Handle,motor_yaw_CHANNAL);
				
			}
		
	}
	
	
	else if (TIMx == motor_pitch_TIM)
	{
		
		if(rc_ctrl.rc.ch[1] >= RC_DeadZone )
			{
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_High);
				//fre = Set_Fre;
				//TIM_Freq_Set(motor_yaw_TIM, fre);
				//HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
				PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
			}
		else if(rc_ctrl.rc.ch[1] <= -RC_DeadZone && pitch_limit_state != 1)
			{
				HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_Low);
				//fre = Set_Fre;
				//TIM_Freq_Set(motor_yaw_TIM, fre);
				//HAL_TIM_PWM_Start(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
				PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
			}
		else
			{
				//HAL_TIM_PWM_Stop(&motor_pitch_TIM_Handle,motor_pitch_CHANNAL);
			}
	}
}

void PWM_Pulse_Control(TIM_TypeDef* TIMx, uint16_t yaw_step, uint16_t pitch_step)
{
	if (TIMx == motor_yaw_TIM)
	{
		if (yaw_PWM_flag == 1)
			{
				if (HAL_GPIO_ReadPin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN) == motor_yaw_Move_Right)
					{
						yaw_position++;
					}
				else if (HAL_GPIO_ReadPin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN) == motor_yaw_Move_Left)
					{
						yaw_position--;
					}
				yaw_PWM_flag = 0;
				__HAL_TIM_SET_AUTORELOAD(&motor_yaw_PWM_Slave_TIM_Handle, yaw_step - 1);
				HAL_TIM_Base_Start_IT(&motor_yaw_PWM_Slave_TIM_Handle);
				HAL_TIM_PWM_Start_IT(&motor_yaw_PWM_Master_TIM_Handle, motor_yaw_CHANNAL);
			}
	}
	
	if(TIMx == motor_pitch_TIM)
	{
		if (pitch_PWM_flag == 1)
			{
				if (HAL_GPIO_ReadPin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN) == motor_pitch_Move_High)
					{
						pitch_position++;
					}
				else if (HAL_GPIO_ReadPin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN) == motor_pitch_Move_Low)
					{
						pitch_position--;
					}
					pitch_PWM_flag = 0;
					__HAL_TIM_SET_AUTORELOAD(&motor_pitch_PWM_Slave_TIM_Handle, pitch_step - 1);
					HAL_TIM_Base_Start_IT(&motor_pitch_PWM_Slave_TIM_Handle);
					HAL_TIM_PWM_Start_IT(&motor_pitch_PWM_Master_TIM_Handle, motor_pitch_CHANNAL);
			}
	} 
	
}




