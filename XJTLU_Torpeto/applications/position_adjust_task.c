#include "position_adjust_task.h"

int pitch_target;
int yaw_target;

uint8_t adjust_flag;

uint8_t pitch_finish_flag;
uint8_t yaw_finish_flag;

void adjust_task(void const * argument)
{
	int temp_pitch;
	int temp_yaw;
	adjust_flag = 1;
	
  while(1)
    {
			temp_pitch = 0;
			temp_yaw = 0;
			
			if(choose_flag == 2 && adjust_flag == 1)
			{
				pitch_target = torpedo_data[torpedo_num].pitch;
				yaw_target		= torpedo_data[torpedo_num].yaw;
				temp_pitch 	= pitch_target - pitch_position;
				temp_yaw		=	yaw_target - yaw_position;
				TIM_Freq_Set(motor_pitch_TIM, 80);
				TIM_Freq_Set(motor_yaw_TIM, 80);
				
				if(temp_pitch > 0)
				{
					HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_High);
					PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
				}
				else if (temp_pitch < 0)
				{
					HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_Low);
					PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
				}
				else 
				{
					pitch_finish_flag = 1;
				}
				
				if (temp_yaw > 0)
				{
					HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Right);
					PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
				}
				else if(temp_yaw < 0)
				{
					HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Left);
					PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
				}
				else
				{
					yaw_finish_flag = 1;
				}
				
				
				if(pitch_finish_flag == 1 && yaw_finish_flag == 1)
				{
					pitch_finish_flag = 0;
					yaw_finish_flag = 0;
					adjust_flag = 2;
				}
				
			}
			
			
			
			if (adjust_flag == 3)
			{
				pitch_target = 0;
				yaw_target		= 0;
				temp_pitch 	= 	pitch_target - pitch_position;
				temp_yaw		=		yaw_target - yaw_position;
				
				if(temp_pitch > 1)
				{
					HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_High);
					PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
				}
				else if (temp_pitch < 1)
				{
					HAL_GPIO_WritePin(motor_pitch_DIR_GPIO, motor_pitch_DIR_PIN, motor_pitch_Move_Low);
					PWM_Pulse_Control(motor_pitch_TIM, pulse_step,pulse_step);
				}
				else 
				{
					pitch_finish_flag = 1;
				}
				
				if (temp_yaw > 1)
				{
					HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Right);
					PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
				}
				else if(temp_yaw < 1)
				{
					HAL_GPIO_WritePin(motor_yaw_DIR_GPIO, motor_yaw_DIR_PIN, motor_yaw_Move_Left);
					PWM_Pulse_Control(motor_yaw_TIM, pulse_step,pulse_step);
				}
				else
				{
					yaw_finish_flag = 1;
				}
				
				
				if(pitch_finish_flag == 1 && yaw_finish_flag == 1)
				{
					pitch_finish_flag = 0;
					yaw_finish_flag = 0;
					adjust_flag = 4;
				}
			}
			
			osDelay(2);
    }
}
