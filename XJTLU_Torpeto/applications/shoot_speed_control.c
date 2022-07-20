#include "shoot_speed_control.h"

fp32 shoot_speed_set;
fp32 shoot_last_speed;
uint8_t shoot_speed_flag = 0;
uint8_t turn_back_flag = 0;
uint16_t turn_back_counter;


fp32 push_speed_set;


void shoot_speed_limit(void)
{
	if(shoot_speed_set > 9500)
	{
		shoot_speed_set = 9500;
	}
	else if (shoot_speed_set <  0)
	{
		shoot_speed_set = 0;
	}
	else
	{
		if (shoot_speed_flag == 0)
		{
			shoot_speed_set =8000;
			shoot_speed_flag = 1;
		}
		else if (shoot_speed_flag == 1)
		{
			shoot_speed_set = shoot_last_speed;
		}
		
		shoot_motor_speed();
		shoot_last_speed = shoot_speed_set;
		
	}
	
}


void shoot_motor_speed(void)
{
	if(rc_ctrl.rc.ch[1] > 200)
	{
		shoot_speed_set += 500;
	}
	else if (rc_ctrl.rc.ch[1] < -200)
	{
		shoot_speed_set -= 500;
	}
	
	if(rc_ctrl.rc.ch[3] > 200)
	{
		shoot_speed_set += 100;
	}
	else if (rc_ctrl.rc.ch[3] < -200)
	{
		shoot_speed_set -= 100;
	}
}

void push_motor_speed(void)
{
	if (rc_ctrl.rc.ch[1] > 20 && push_high_state != 1 && turn_back_flag == 0)
	{
		push_speed_set = 17000;
	}
	else if (rc_ctrl.rc.ch[1] < -20 && push_low_state != 1 && turn_back_flag == 0)
	{
		push_speed_set = -17000;
	}
	else if(turn_back_flag == 1 && rc_ctrl.rc.s[1] == 2 && rc_ctrl.rc.s[0] == 2 )
	{
		push_speed_set = -17000;
	}
	else
	{
		push_speed_set = 0;
	}
}



void shoot_speed_task(void const * argument)
{
  while(1)
    {
			
			if (push_high_state == 1)
			{
				turn_back_flag = 1;
			}
			
			if(turn_back_flag == 1 && rc_ctrl.rc.s[1] == 2 && rc_ctrl.rc.s[0] == 2)
			{
				turn_back_counter++;
				
				if(turn_back_counter >= turn_back_time || push_low_state == 1)
				{
					turn_back_counter = 0;
					turn_back_flag = 0;
				}
			}
			
			if (rc_ctrl.rc.s[1] != 1 )
			{
				user_pid_Calc();
				CAN_cmd_Torpedo(ShootMotor1.out, ShootMotor2.out, PushMotor.out);				
			}
			
			osDelay(2);
    }
}




	


