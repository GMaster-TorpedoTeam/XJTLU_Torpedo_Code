#include "StepMotor_position_reset_task.h"

uint8_t StepMotor_reset_flag = 0;
uint8_t position_reset_flag = 0;


//两边拨杆拨中，遥杆\/进行步进电机位置重置
void step_motor_reset_task(void const * argument)
{
  while(1)
    {
			
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
			
			
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] > 500 && rc_ctrl.rc.ch[1] > 500
				&& rc_ctrl.rc.ch[2] < -500 && rc_ctrl.rc.ch[3] > 500)
			{
				position_reset_flag++;
				if (position_reset_flag == 5)
				{
					adjust_flag = 3;
					StepMotor_reset_flag = 0;
				}
			}
			
			osDelay(100);
    }
}
