#include "StepMotor_position_reset_task.h"

uint8_t StepMotor_reset_flag = 0;
uint8_t position_reset_flag = 0;
uint8_t test_speed_flag = 0;


void step_motor_reset_task(void const * argument)
{
  while(1)
    {
			
			//���߲��˲��У�ң��\/���ڰ�  ����ǰλ��д��flash
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] < -500 && rc_ctrl.rc.ch[1] < -500
				&& rc_ctrl.rc.ch[2] > 500 && rc_ctrl.rc.ch[3] < -500)
			{
				StepMotor_reset_flag++;
				
				if (StepMotor_reset_flag == 5)
				{
					pitch_data[0] = pitch_position;
					yaw_data[0]		= yaw_position;
					
					launcher_data_write();
					
					StepMotor_reset_flag = 0;
				}
			}
			
			
			//���߲��˲��У�ң��/\����� ��ȡflash����ֵ�����ƶ�
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] > 500 && rc_ctrl.rc.ch[1] < -500
				&& rc_ctrl.rc.ch[2] < -500 && rc_ctrl.rc.ch[3] < -500)
			{
				
				position_reset_flag++;
				if (position_reset_flag == 5)
				{
					launcher_data_read();
					pitch_target 	= 	pitch_data[0];
					yaw_target		= 	yaw_data[0];
					
					adjust_flag = 4;
					position_reset_flag = 0;
					competition_start_flag = 0;
				}
				
			}
			
			
				
			//���߲��˲��У�ң��\/����� �л�����/����Ħ����ת��
			if (rc_ctrl.rc.s[1] == 3 && rc_ctrl.rc.s[0] == 3 && rc_ctrl.rc.ch[0] > 500 && rc_ctrl.rc.ch[1] > 500
				&& rc_ctrl.rc.ch[2] < -500 && rc_ctrl.rc.ch[3] > 500)
			{
				
				test_speed_flag++;
				if (test_speed_flag == 5)
				{
					if(test_flag == 0)
					{
						test_flag = 1;
						test_speed_flag = 0;
					}
					else if(test_flag == 1)
					{
						test_flag = 0;
						test_speed_flag = 0;
					}
				}
				
			}
			
			
			osDelay(100);
    }
}
