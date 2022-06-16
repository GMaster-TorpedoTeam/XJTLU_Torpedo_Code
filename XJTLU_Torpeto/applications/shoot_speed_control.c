#include "shoot_speed_control.h"

fp32 shoot_speed_set;
fp32 shoot_last_speed;
uint8_t shoot_speed_flag = 0;


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
}

void push_motor_speed(void)
{
	if (rc_ctrl.rc.ch[1] > 20 && push_high_state != 1)
	{
		push_speed_set = 17000;
	}
	else if (rc_ctrl.rc.ch[1] < -20)
	{
		push_speed_set = -17000;
	}
	
	else
	{
		push_speed_set = 0;
	}
}





	


