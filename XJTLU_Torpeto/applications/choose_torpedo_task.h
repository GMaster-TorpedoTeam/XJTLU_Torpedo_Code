#ifndef CHOOSE_TORPEDO_TASK_H
#define CHOOSE_TORPEDO_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"

extern uint8_t finish_flag;

extern void choose_task(void const * argument);


#endif
