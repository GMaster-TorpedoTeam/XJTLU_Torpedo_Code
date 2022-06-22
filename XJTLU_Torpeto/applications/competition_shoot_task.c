#include "competition_shoot_task.h"

uint8_t c_shoot_flag = 0;
fp32 c_shoot_motor_speed;
uint8_t c_shoot_report = 0;
uint16_t shoot_delay_flag = 0;

void c_shoot_task(void const * argument)
{
  while(1)
    {
			
			if (adjust_flag == 2 && (rc_ctrl.rc.ch[4] > 500 || rc_ctrl.key.v == KEY_PRESSED_OFFSET_G) && c_shoot_report == 0)
			{
				c_shoot_flag = 1;
			}
			
			if (c_shoot_flag == 0)
			{
				c_shoot_motor_speed = 0;
			}
			else if(c_shoot_flag == 1)
			{
				c_shoot_motor_speed = shoot_speed;
				
				shoot_delay_flag++;
				if (shoot_delay_flag == 300)
				{
					c_shoot_report = 1;
					shoot_delay_flag = 0;
				}
				
			}
			
			osDelay(2);
    }
}

