#include "competition_mode_task.h"


uint8_t competition_start_flag = 0;

void competition_mode_task(void const * argument)
{
  while(1)
    {
			if(rc_ctrl.rc.s[1] == 1)
			{
				HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8, GPIO_PIN_SET);
			}
			
			if(rc_ctrl.rc.s[1] == 1 && competition_start_flag == 0)
			{
				choose_flag = 1;
				competition_start_flag = 1;
			}
			
			osDelay(2);
    }
}
