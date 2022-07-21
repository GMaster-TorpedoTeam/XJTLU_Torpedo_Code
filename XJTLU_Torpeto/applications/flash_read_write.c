#include "flash_read_write.h"

uint8_t pitch_data[FLASH_DATA_LENGHT];
uint8_t yaw_data[FLASH_DATA_LENGHT];

void launcher_data_read(void)
{
	flash_read(USER_FLASH_ADDRESS, (uint32_t *)pitch_data, (FLASH_DATA_LENGHT + 3) / 4);
	flash_read(USER_FLASH_ADDRESS, (uint32_t *)yaw_data, (FLASH_DATA_LENGHT + 3) / 4);
}



void launcher_data_write(void)
{
	flash_erase_address(USER_FLASH_ADDRESS, 1);
	flash_write_single_address(USER_FLASH_ADDRESS, (uint32_t *)pitch_data, (FLASH_DATA_LENGHT + 3) / 4);
	flash_write_single_address(USER_FLASH_ADDRESS+0x15, (uint32_t *)yaw_data, (FLASH_DATA_LENGHT + 3) / 4);
}

