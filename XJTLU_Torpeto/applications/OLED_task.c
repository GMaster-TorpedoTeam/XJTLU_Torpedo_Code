#include "OLED_task.h"



void oled_show_task(void const * argument)
{
  while(1)
    {
			OLED_ShowFNum(Motor1_Data_row , Motor1_Data_col, motor_chassis[0].speed_rpm);
			OLED_ShowFNum(Motor2_Data_row , Motor2_Data_col, motor_chassis[1].speed_rpm);
	
			OLED_refresh_gram();
			osDelay(2);
    }
}

