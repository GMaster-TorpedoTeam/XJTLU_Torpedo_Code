#ifndef POSITION_ADJUST_TASK_H
#define POSITION_ADJUST_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "cmsis_os.h"
#include "Torpedo_data.h"
#include "bsp_StepMotor.h"
#include "step_motor_task.h"
#include "flash_read_write.h"

extern Torpedo_data_t torpedo_data[Torpedo_number];
extern uint8_t torpedo_num;
extern uint8_t choose_flag;
extern int yaw_position;
extern int pitch_position;
extern uint8_t pitch_data[FLASH_DATA_LENGHT];
extern uint8_t yaw_data[FLASH_DATA_LENGHT];

extern void adjust_task(void const * argument);


#endif
