#ifndef USER_PID_H
#define USER_PID_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "main.h"
#include "pid.h"
#include "shoot_speed_control.h"
#include "CAN_receive.h"
#include "competion_step_motor_task.h"

extern motor_measure_t motor_chassis[7];
extern fp32 shoot_speed_set;
extern fp32 push_speed_set;
extern fp32 c_step_motor_speed;
extern fp32 c_shoot_speed_set;

//摩擦轮1速度环PID
#define ShootMOTOR1_SPEED_PID_KP 50.0f
#define ShootMOTOR1_SPEED_PID_KI 0.001f
#define ShootMOTOR1_SPEED_PID_KD 0.9f
#define ShootMOTOR1_SPEED_PID_MAX_OUT 16000.0f
#define ShootMOTOR1_SPEED_PID_MAX_IOUT 2000.0f

//摩擦轮2速度环PID
#define ShootMOTOR2_SPEED_PID_KP 50.0f
#define ShootMOTOR2_SPEED_PID_KI 0.001f
#define ShootMOTOR2_SPEED_PID_KD 0.9f
#define ShootMOTOR2_SPEED_PID_MAX_OUT 16000.0f
#define ShootMOTOR2_SPEED_PID_MAX_IOUT 2000.0f

//推杆电机位置环PID
#define PushMotor_GYRO_ABSOLUTE_PID_KP 15.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KI 0.0f
#define PushMotor_GYRO_ABSOLUTE_PID_KD 0.7f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_OUT 5500.0f
#define PushMotor_GYRO_ABSOLUTE_PID_MAX_IOUT 0.0f

//推杆电机速度环PID
#define PushMotor_SPEED_PID_KP 15.0f
#define PushMotor_SPEED_PID_KI 0.001f
#define PushMotor_SPEED_PID_KD 0.09f
#define PushMotor_SPEED_PID_MAX_OUT 17000.0f
#define PushMotor_SPEED_PID_MAX_IOUT 10.0f

//初始化所有PID的结构体
void user_pid_Init(void);
//计算PID
void user_pid_Calc(void);

#endif
