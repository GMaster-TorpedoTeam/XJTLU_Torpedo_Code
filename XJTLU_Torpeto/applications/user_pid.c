#include "user_pid.h"

//摩擦轮电机1PID参数和PID结构体
fp32 ShootMotor1PID[3] = {ShootMOTOR1_SPEED_PID_KP, ShootMOTOR1_SPEED_PID_KI, ShootMOTOR1_SPEED_PID_KD};
pid_type_def ShootMotor1;

//摩擦轮电机2PID参数和PID结构体
fp32 ShootMotor2PID[3] = {ShootMOTOR2_SPEED_PID_KP, ShootMOTOR2_SPEED_PID_KI, ShootMOTOR2_SPEED_PID_KD};
pid_type_def ShootMotor2;


//推杆电机PID参数和PID结构体
fp32 PushMotorPID[3] = {PushMotor_SPEED_PID_KP, PushMotor_SPEED_PID_KI, PushMotor_SPEED_PID_KD};
pid_type_def PushMotor;


void user_pid_Init(void)
{
	PID_init(&ShootMotor1, PID_POSITION, ShootMotor1PID, ShootMOTOR1_SPEED_PID_MAX_OUT, ShootMOTOR1_SPEED_PID_MAX_IOUT);
	PID_init(&ShootMotor2, PID_POSITION, ShootMotor2PID, ShootMOTOR2_SPEED_PID_MAX_OUT, ShootMOTOR2_SPEED_PID_MAX_IOUT);
	PID_init(&PushMotor, PID_POSITION, PushMotorPID, PushMotor_SPEED_PID_MAX_OUT, PushMotor_SPEED_PID_MAX_IOUT);
}


void user_pid_Calc(void)
{
	PID_calc(&ShootMotor1, motor_chassis[0].speed_rpm, -shoot_speed_set);
	PID_calc(&ShootMotor2, motor_chassis[1].speed_rpm, shoot_speed_set);
	PID_calc(&PushMotor, motor_chassis[2].speed_rpm, push_speed_set);
}

