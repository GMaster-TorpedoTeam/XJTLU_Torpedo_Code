#ifndef FLASH_READ_WRITE_H
#define FLASH_READ_WRITE_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

#include "bsp_flash.h"

#define USER_FLASH_ADDRESS  ADDR_FLASH_SECTOR_11
#define FLASH_DATA_LENGHT   10

void launcher_data_read(void);
void launcher_data_write(void);

#endif
