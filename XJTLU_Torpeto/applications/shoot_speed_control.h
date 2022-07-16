#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H
#include "struct_typedef.h"
#include "remote_control.h"

#include "bsp_StepMotor.h"
#include "pid.h"
#include "CAN_receive.h"
#include "cmsis_os.h"
#include "user_pid.h"

#define turn_back_time 2400

extern RC_ctrl_t rc_ctrl;
extern pid_type_def ShootMotor1;
extern pid_type_def ShootMotor2;
extern pid_type_def PushMotor;

extern motor_measure_t motor_chassis[7];

void shoot_speed_limit(void);
void shoot_motor_speed(void);

void push_motor_speed(void);
extern void shoot_speed_task(void const * argument);



#endif
