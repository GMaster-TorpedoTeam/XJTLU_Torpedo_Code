#include "bsp_competition_mode.h"

uint8_t step_motor_active_flag = 0;
bool_t half_flag = 0;

int round_num;
fp32 push_gyro_out;

void Move_Step_Motor(int round)
{
	if ()
		if(step_motor_active_flag == 0)
		{
			round_num = round;
			step_motor_active_flag = 1;
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
				C_set_step_motor = C_PushMotor_SPEED.out;
		
				if (motor_chassis[2].ecd >= 8000 && motor_chassis[2].ecd < 8191)
					{
						half_flag = 1;
					}
				else if(motor_chassis[2].ecd >= 3500 && motor_chassis[2].ecd < 4095)
					{
						half_flag = 0;
						round_num--;
					}
		
				if ( round_num <= 0 || push_high_state == 1 || push_low_state == 1)
					{
						round_num = 0;
						step_motor_active_flag = 0;
						c_shoot_report = 0;
					}
			}
			
			else if (round_num < -2)
			{
				if(push_low_state != 1)
				{
					PID_calc(&C_PushMotor_SPEED, motor_chassis[2].speed_rpm, -15000);
					C_set_step_motor = C_PushMotor_SPEED.out;
				}
			}
		
	
}
