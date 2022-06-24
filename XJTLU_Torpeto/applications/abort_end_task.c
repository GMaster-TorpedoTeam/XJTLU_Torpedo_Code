#include "abort_end_task.h"

uint8_t circle_counter = 0;
uint8_t finish_flag = 0;

void abort_end_task(void const * argument)
{
  while(1)
    {
			
			if (finish_flag == 1 )
			{
				choose_flag = 1;
				adjust_flag = 1;
				c_shoot_report = 0;
				c_step_flag = 0;
				finish_flag = 0;
				circle_counter++;
			}
			
			if (end_flag == 1)
			{
				choose_flag = 0;
				adjust_flag = 3;
				c_shoot_report = 0;
				c_step_flag = 2;
				finish_flag = 0;
				circle_counter = 0;
				end_flag = 0;
				delay_counter = 0;
			}
			
			osDelay(2);
    }
}

