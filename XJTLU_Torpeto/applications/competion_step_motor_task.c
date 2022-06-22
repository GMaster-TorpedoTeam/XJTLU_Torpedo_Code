#include "competion_step_motor_task.h"

uint8_t c_step_flag = 0;
fp32 c_step_motor_speed;
uint16_t delay_counter = 0;
uint8_t end_flag = 0;

void c_step_task(void const * argument)
{
  while(1)
    {
			
			if (c_shoot_report == 1 && c_step_flag == 0)
			{
				c_step_flag = 1;
			}
			
			if (c_step_flag == 0 || c_step_flag == 3)
			{
				c_step_motor_speed = 0;
			}
			else if (c_step_flag == 1 && push_high_state != 1)
			{
				c_step_motor_speed = 17000;
				
				delay_counter++;
				if (delay_counter == delay_time)
				{
					c_step_flag = 3;
					c_shoot_flag = 0;
					finish_flag = 1;
				}
				
			}
			else if (c_step_flag == 2 && push_low_state != 0)
			{
				c_step_motor_speed = -17000;
			}
			
			if (push_high_state == 1)
			{
				c_step_flag = 3;
				c_shoot_flag = 0;
				end_flag = 1;
			}
			
			if ( push_low_state == 1)
			{
				c_step_flag = 0;
				c_shoot_flag = 0;
			}
			
			user_pid_Calc();
			CAN_cmd_Torpedo(ShootMotor1.out, ShootMotor2.out, C_PushMotor_SPEED.out);
			
			osDelay(2);
    }
}

