#include "StepMotor_position_reset_task.h"

uint8_t StepMotor_reset_flag = 0;

void step_motor_reset_task(void const * argument)
{
  while(1)
    {
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] < -600 && rc_ctrl.rc.ch[1] < -600
				&& rc_ctrl.rc.ch[2] > 600 && rc_ctrl.rc.ch[3] < -600)
	{
		StepMotor_reset_flag++;
		
		if (StepMotor_reset_flag == 4)
			{
				yaw_position = 0;
				pitch_position = 0;
				StepMotor_reset_flag = 0;
			}
	}
			osDelay(100);
    }
}
