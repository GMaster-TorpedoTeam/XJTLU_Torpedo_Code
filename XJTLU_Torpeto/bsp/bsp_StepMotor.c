#include "bsp_StepMotor.h"
#include "main.h"
#include <stdio.h>

uint8_t yaw_PWM_flag  = 0;
uint8_t pitch_PWM_flag  = 0;

void TIM_Freq_Set(TIM_TypeDef* TIMx, uint32_t Freq)
{
	
	TIMx->PSC = Freq; 
  TIMx->EGR = TIM_EGR_UG;         //修改之后要更新寄存器
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == (&motor_yaw_PWM_Slave_TIM_Handle))
    {
        if(__HAL_TIM_GET_FLAG(&motor_yaw_PWM_Slave_TIM_Handle, TIM_FLAG_CC1) != RESET)
        {
            __HAL_TIM_CLEAR_FLAG(&motor_yaw_PWM_Slave_TIM_Handle, TIM_FLAG_CC1);
            HAL_TIM_PWM_Stop_IT(&motor_yaw_PWM_Master_TIM_Handle, motor_yaw_CHANNAL);
            HAL_TIM_Base_Stop_IT(&motor_yaw_PWM_Slave_TIM_Handle);
        }
        yaw_PWM_flag = 1;
    }
		
		if(htim == (&motor_pitch_PWM_Slave_TIM_Handle))
    {
        if(__HAL_TIM_GET_FLAG(&motor_pitch_PWM_Slave_TIM_Handle, TIM_FLAG_CC1) != RESET)
        {
            __HAL_TIM_CLEAR_FLAG(&motor_pitch_PWM_Slave_TIM_Handle, TIM_FLAG_CC1);
            HAL_TIM_PWM_Stop_IT(&motor_pitch_PWM_Master_TIM_Handle, motor_pitch_CHANNAL);
            HAL_TIM_Base_Stop_IT(&motor_pitch_PWM_Slave_TIM_Handle);
        }
        pitch_PWM_flag = 1;
    }
		
		
		if (htim->Instance == TIM2) 
			{
				HAL_IncTick();
			}
}
