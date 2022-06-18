#ifndef REFEREE_SENT_TASK_H
#define REFEREE_SENT_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "remote_control.h"
#include "bsp_referee_sent.h"

#define referee_state rc_ctrl.rc.s[1]

extern RC_ctrl_t rc_ctrl;

extern void referee_send_task(void const * argument);

#endif
