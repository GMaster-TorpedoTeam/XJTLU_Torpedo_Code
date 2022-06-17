#include "OLED_task.h"



void oled_show_task(void const * argument)
{
  while(1)
    {
			OLED_ShowFNum(50, 2, 	motor_chassis[0].speed_rpm, 12);
			OLED_ShowFNum(50, 16, motor_chassis[1].speed_rpm, 12);
	
			OLED_Refresh();
			osDelay(200);
    }
}

