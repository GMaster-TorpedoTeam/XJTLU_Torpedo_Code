#ifndef ABORT_END_TASK_H
#define ABORT_END_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"
#include "remote_control.h"

extern RC_ctrl_t rc_ctrl;

extern uint8_t choose_flag;
extern uint8_t adjust_flag;
extern uint8_t c_shoot_report;
extern uint8_t c_step_flag;
extern uint8_t end_flag;

extern void abort_end_task(void const * argument);

#endif
