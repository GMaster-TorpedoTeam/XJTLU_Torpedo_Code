#include "competition_mode_task.h"

//////////////////////////
bool_t 	Move_flag 		= 0;
bool_t 	button_flag 	= 0;
bool_t 	send_flag 		= 0;
bool_t 	half_flag 		= 0;

int round_num = 0;
fp32 push_gyro_out;
fp32 push_speed_out;

void Move_Step_Motor(void)
{
	
	if (Move_flag == 1)
		{
			round_num = StepMotor_Move_round;
			Move_flag = 0;
			send_flag = 1;
		}
		
	if(round_num > 0)
	{
		if(half_flag == 0)
		{
			PID_calc(&C_PushMotor_GYRO, motor_chassis[2].ecd, 8191);
		}
		else if(half_flag == 1)
		{
			PID_calc(&C_PushMotor_GYRO, motor_chassis[2].ecd, 4095);
		}
	
		if(C_PushMotor_GYRO.out < 0 )
		{
			push_gyro_out = -C_PushMotor_GYRO.out;
		}
		else 
		{
			push_gyro_out = C_PushMotor_GYRO.out;
		}
		
		if( push_gyro_out > 17000)
		{
			push_gyro_out = 17000;
		}
		
		PID_calc(&C_PushMotor_SPEED, motor_chassis[2].speed_rpm, push_gyro_out*3);
		push_speed_out = C_PushMotor_SPEED.out;
		
		if (motor_chassis[2].ecd >= 8000 && motor_chassis[2].ecd < 8191)
		{
			half_flag = 1;
		}
		else if(motor_chassis[2].ecd >= 3500 && motor_chassis[2].ecd < 4095)
		{
			half_flag = 0;
			round_num--;
		}
		
		if (round_num <= 0 || push_high_state == 1 || push_low_state == 1)
		{
			round_num = 0;
			Move_flag 		= 0;
			button_flag 	= 0;
			send_flag 		= 0;
		}
	
	
	
	
	}
}


void competition_mode_task(void const * argument)
{
  while(1)
    {
			
			if (rc_ctrl.rc.s[1] == 1 )
			{
				
				if(rc_ctrl.rc.ch[4] > 100 && button_flag == 0 && Move_flag == 0)
				{
					button_flag = 1;
					Move_flag = 1;
				}
				else if(send_flag == 0)
				{
					PID_calc(&C_PushMotor_SPEED, motor_chassis[2].speed_rpm, 0);
					push_speed_out = C_PushMotor_SPEED.out;
				}
				
				Move_Step_Motor();
				
				shoot_speed_limit();
				user_pid_Calc();
			
				CAN_cmd_Torpedo(ShootMotor1.out, ShootMotor2.out, push_speed_out);

			}
			
			osDelay(4);
    }
}
