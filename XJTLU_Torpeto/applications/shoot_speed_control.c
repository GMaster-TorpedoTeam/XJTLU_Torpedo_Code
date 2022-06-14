#include "shoot_speed_control.h"

uint16_t set_speed;
uint8_t set_flag;

//调用后续所有函数
void speed_set(void)
{
	speed_Limit();
	s1();
}

//判断电机转速是否超过范围，防止电机倒转。如果转速处于正常范围，调用s0()对电机进行调速。
void speed_Limit(void)
{
	if(set_speed > 9000)
	{
		set_speed = 9000;
	}
	else if (set_speed <  0)
	{
		set_speed = 0;
	}
	else
	{
		if(rc_ctrl.rc.s[1] == 0x01)
		{
			s0();
		}
		
		if(set_speed != 0)
		{
			last_speed = set_speed;
		}
	}
}

/*三档调速。
	gear_max(),每200ms变动1500；
	gear_mid(),每200ms变动200；
	gear_min(),每200ms变动5；
*/
void s0(void)
{
	if(rc_ctrl.rc.s[0] == 0x01)
	{
		gear_max();
	}
	else if(rc_ctrl.rc.s[0] == 0x03)
	{
		gear_mid();
	}
	else if(rc_ctrl.rc.s[0] == 0x02)
	{
		gear_min();
	}
}

/*根据遥控器rc_ctrl.rc.s[1]的数值：
	0x01:启动摩擦轮,转速设为4000；
	0x03:刹车。
*/
void s1(void)
{
	if(rc_ctrl.rc.s[1] == 0x03)
	{
		set_speed = 0;
		set_flag = 0;
	}
	
	
	if(rc_ctrl.rc.s[1] == 0x01 && set_flag == 0)
	{
		if(last_speed == 0)
		{
			set_speed = 500;
			set_flag = 1;
		}
		else
		{
			set_speed = last_speed;
		}
	}
}





void gear_max()
{
	if(rc_ctrl.rc.ch[1] > 200)
	{
		set_speed += 1000;
	}
	else if (rc_ctrl.rc.ch[1] < -200)
	{
		set_speed -= 1000;
	}
}
	
void gear_mid()		
{
	if(rc_ctrl.rc.ch[1] > 200)
	{
		set_speed += 200;
	}
	else if (rc_ctrl.rc.ch[1] < -200)
	{
		set_speed -= 200;
	}
}
	
void gear_min()
{
	if(rc_ctrl.rc.ch[1] > 200)
	{
		set_speed += 5;
	}
	else if (rc_ctrl.rc.ch[1] < -200)
	{
		set_speed -= 5;
	}
}
	


