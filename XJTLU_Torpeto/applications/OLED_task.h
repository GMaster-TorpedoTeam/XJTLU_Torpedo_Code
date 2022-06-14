#ifndef OLED_TASK_H
#define OLED_TASK_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "main.h" 
#include "OLED.h" 
#include "CAN_receive.h"

extern motor_measure_t motor_chassis[7];



#define Motor1_Data_col 8
#define Motor1_Data_row 0

#define Motor2_Data_col 8
#define Motor2_Data_row 1

void OLED_Show(void);


#endif
