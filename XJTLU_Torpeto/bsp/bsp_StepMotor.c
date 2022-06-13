#include "bsp_StepMotor.h"
#include "main.h"
#include <stdio.h>

extern RC_ctrl_t rc_ctrl;
extern TIM_HandleTypeDef htim1;

void TIM_Freq_Set(TIM_TypeDef* TIMx, uint32_t Freq)
{
	
	TIMx->PSC = Freq; 
  TIMx->EGR = TIM_EGR_UG;         //修改之后要更新寄存器
}



