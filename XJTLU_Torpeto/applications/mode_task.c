#include "mode_task.h"

uint8_t shoot_speed_count_flag = 0;
uint8_t stepmotor_count_flag = 0;

void mode_choose(void)
{
	if (rc_ctrl.rc.s[1] == 3 )
	{
		//刹车模式
		shoot_speed_set = 0;
		push_speed_set = 0;
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_RESET);
	}
	
	else if (rc_ctrl.rc.s[1] == 2 && rc_ctrl.rc.s[0] == 1 && shoot_speed_count_flag == 100)
	{
		//调整摩擦轮速度
		shoot_speed_limit();
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_SET);
	}
	
	else if (rc_ctrl.rc.s[1] == 2 && rc_ctrl.rc.s[0] == 3 )
	{
		//调整步进电机
		rc2StepMotor(motor_yaw_TIM);
		rc2StepMotor(motor_pitch_TIM);
		shoot_speed_count_flag = 0;
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_SET);
	}
	
	else if(rc_ctrl.rc.s[1] == 2 && rc_ctrl.rc.s[0] == 2)
	{
		push_motor_speed();
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_SET);
	}
	
	user_pid_Calc();
	shoot_speed_count_flag = shoot_speed_count_flag + 1;
	stepmotor_count_flag = stepmotor_count_flag + 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	mode_choose();
}

