#include "user_pid.h"

//Ħ���ֵ��1PID������PID�ṹ��
fp32 ShootMotor1PID[3] = {ShootMOTOR1_SPEED_PID_KP, ShootMOTOR1_SPEED_PID_KI, ShootMOTOR1_SPEED_PID_KD};
pid_type_def ShootMotor1;

//Ħ���ֵ��2PID������PID�ṹ��
fp32 ShootMotor2PID[3] = {ShootMOTOR2_SPEED_PID_KP, ShootMOTOR2_SPEED_PID_KI, ShootMOTOR2_SPEED_PID_KD};
pid_type_def ShootMotor2;


//�Ƹ˵��PID������PID�ṹ��
fp32 PushMotorPID[3] = {PushMotor_SPEED_PID_KP, PushMotor_SPEED_PID_KI, PushMotor_SPEED_PID_KD};
pid_type_def PushMotor;

//һ������ģʽ���Ƹ˵��λ�û�PID�����ͽṹ��
fp32 C_PushMotor_GYRO_PID[3] = {PushMotor_GYRO_ABSOLUTE_PID_KP, PushMotor_GYRO_ABSOLUTE_PID_KI, 
PushMotor_GYRO_ABSOLUTE_PID_KD};
pid_type_def C_PushMotor_GYRO;

//һ������ģʽ���Ƹ˵���ٶȻ�PID�����ͽṹ��
fp32 C_PushMotor_SPEED_PID[3] = {PushMotor_SPEED_PID_KP, PushMotor_SPEED_PID_KI, PushMotor_SPEED_PID_KD};
pid_type_def C_PushMotor_SPEED;



void user_pid_Init(void)
{
	PID_init(&ShootMotor1, PID_POSITION, ShootMotor1PID, ShootMOTOR1_SPEED_PID_MAX_OUT, ShootMOTOR1_SPEED_PID_MAX_IOUT);
	PID_init(&ShootMotor2, PID_POSITION, ShootMotor2PID, ShootMOTOR2_SPEED_PID_MAX_OUT, ShootMOTOR2_SPEED_PID_MAX_IOUT);
	PID_init(&PushMotor, PID_POSITION, PushMotorPID, PushMotor_SPEED_PID_MAX_OUT, PushMotor_SPEED_PID_MAX_IOUT);
	PID_init(&C_PushMotor_GYRO, PID_POSITION, C_PushMotor_GYRO_PID, PushMotor_GYRO_ABSOLUTE_PID_MAX_OUT, PushMotor_SPEED_PID_MAX_IOUT);
	PID_init(&C_PushMotor_SPEED, PID_POSITION, C_PushMotor_SPEED_PID, PushMotor_SPEED_PID_MAX_OUT, PushMotor_SPEED_PID_MAX_IOUT);
}


void user_pid_Calc(void)
{
	PID_calc(&ShootMotor1, motor_chassis[0].speed_rpm, -shoot_speed_set);
	PID_calc(&ShootMotor2, motor_chassis[1].speed_rpm, shoot_speed_set);
	PID_calc(&PushMotor, motor_chassis[2].speed_rpm, push_speed_set);
	PID_calc(&C_PushMotor_SPEED, motor_chassis[2].speed_rpm, c_step_motor_speed);
}

