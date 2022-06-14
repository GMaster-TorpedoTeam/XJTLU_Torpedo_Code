#ifndef USER_PID_H
#define USER_PID_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "main.h"
#include "pid.h"
#include "shoot_speed_control.h"
#include "CAN_receive.h"

extern motor_measure_t motor_chassis[7];
extern uint16_t shoot_speed_set;
extern uint16_t push_speed_set;

//Ħ����1�ٶȻ�PID
#define ShootMOTOR1_SPEED_PID_KP 30.0
#define ShootMOTOR1_SPEED_PID_KI 0.001
#define ShootMOTOR1_SPEED_PID_KD 0.8
#define ShootMOTOR1_SPEED_PID_MAX_OUT 16000
#define ShootMOTOR1_SPEED_PID_MAX_IOUT 2000.0

//Ħ����2�ٶȻ�PID
#define ShootMOTOR2_SPEED_PID_KP 30.0
#define ShootMOTOR2_SPEED_PID_KI 0.001
#define ShootMOTOR2_SPEED_PID_KD 0.8
#define ShootMOTOR2_SPEED_PID_MAX_OUT 16000
#define ShootMOTOR2_SPEED_PID_MAX_IOUT 2000.0

//�Ƹ˵��λ�û�PID
#define PushMotor_GYRO_ABSOLUTE_PID_KP 15.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KI 0.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KD -0.7f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_OUT 10.0f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

//�Ƹ˵���ٶȻ�PID
#define PushMotor_SPEED_PID_KP 400.0
#define PushMotor_SPEED_PID_KI 0.01
#define PushMotor_SPEED_PID_KD 9
#define PushMotor_SPEED_PID_MAX_OUT 1000
#define PushMotor_SPEED_PID_MAX_IOUT 10.0

//��ʼ������PID�Ľṹ��
void user_pid_Init(void);
//����PID
void user_pid_Calc(void);

#endif
