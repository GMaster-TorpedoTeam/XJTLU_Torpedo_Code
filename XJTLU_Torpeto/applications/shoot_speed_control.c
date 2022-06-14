#include "shoot_speed_control.h"

uint16_t set_speed;
uint8_t set_flag;

//���ú������к���
void speed_set(void)
{
	speed_Limit();
	s1();
}

//�жϵ��ת���Ƿ񳬹���Χ����ֹ�����ת�����ת�ٴ���������Χ������s0()�Ե�����е��١�
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

/*�������١�
	gear_max(),ÿ200ms�䶯1500��
	gear_mid(),ÿ200ms�䶯200��
	gear_min(),ÿ200ms�䶯5��
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

/*����ң����rc_ctrl.rc.s[1]����ֵ��
	0x01:����Ħ����,ת����Ϊ4000��
	0x03:ɲ����
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
	


