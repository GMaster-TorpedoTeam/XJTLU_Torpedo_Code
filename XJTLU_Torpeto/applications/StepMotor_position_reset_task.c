#include "StepMotor_position_reset_task.h"

uint8_t StepMotor_reset_flag = 0;
uint8_t position_reset_flag = 0;
uint8_t test_speed_flag = 0;


void step_motor_reset_task(void const * argument)
{
  while(1)
    {
			
			//两边拨杆拨中，遥杆\/下内八 步进电机脉冲数归零
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] < -500 && rc_ctrl.rc.ch[1] < -500
				&& rc_ctrl.rc.ch[2] > 500 && rc_ctrl.rc.ch[3] < -500)
			{
				StepMotor_reset_flag++;
				
				if (StepMotor_reset_flag == 5)
				{
					yaw_position = 0;
					pitch_position = 0;
					StepMotor_reset_flag = 0;
				}
			}
			
			
			
			//两边拨杆拨中，遥杆\/上外八 步进电机移动至初始位置
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] > 500 && rc_ctrl.rc.ch[1] > 500
				&& rc_ctrl.rc.ch[2] < -500 && rc_ctrl.rc.ch[3] > 500)
			{
				position_reset_flag++;
				if (position_reset_flag == 5)
				{
					adjust_flag = 3;
					position_reset_flag = 0;
					competition_start_flag = 0;
				}
				
			}
			
			//两边拨杆拨中，遥杆/\下外八 切换测试/比赛摩擦轮转速
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] > 500 && rc_ctrl.rc.ch[1] < -500
				&& rc_ctrl.rc.ch[2] < -500 && rc_ctrl.rc.ch[3] < -500)
			{
				test_speed_flag++;
				if (test_speed_flag == 5)
				{
					if(test_flag == 0)
					{
						test_flag = 1;
					}
					else if(test_flag == 1)
					{
						test_flag = 0;
					}
				}
			}
			
			osDelay(100);
    }
}
