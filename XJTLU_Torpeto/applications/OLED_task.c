#include "OLED_task.h"



void oled_show_task(void const * argument)
{
  while(1)
    {
			OLED_ShowFNum(25, 2, 	motor_chassis[0].speed_rpm, 12);
			OLED_ShowFNum(25, 16, motor_chassis[1].speed_rpm, 12);
			if(robot_state.robot_id == 8)
			{
				OLED_ShowString(90,2, "red",12);
			}
			else if (robot_state.robot_id == 108)
			{
				OLED_ShowString(90,2, "blue",12);
			}
	
			OLED_Refresh();
			osDelay(80);
    }
}

