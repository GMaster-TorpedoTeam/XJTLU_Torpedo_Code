#include "position_adjust_task.h"

uint16_t pitch_pos;
uint16_t yaw_pos;

uint8_t adjust_flag = 0;

void adjust_task(void const * argument)
{
  while(1)
    {
			pitch_pos = torpedo_data[torpedo_num].pitch;
			yaw_pos 	= torpedo_data[torpedo_num].yaw;
			
			if(choose_flag == 1 && adjust_flag == 1)
			{
				
			}
			
			osDelay(2);
    }
}
