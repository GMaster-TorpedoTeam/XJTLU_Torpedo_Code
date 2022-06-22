#ifndef COMPETITION_STEP_MOTOR_TASK_H
#define COMPETITION_STEP_MOTOR_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"
#include "user_pid.h"
#include "bsp_StepMotor.h"
 #include "competition_shoot_task.h" 

#define delay_time 2000

extern uint8_t c_shoot_report;
extern pid_type_def C_PushMotor_SPEED;
extern uint8_t c_shoot_flag;

extern void c_step_task(void const * argument);


#endif
