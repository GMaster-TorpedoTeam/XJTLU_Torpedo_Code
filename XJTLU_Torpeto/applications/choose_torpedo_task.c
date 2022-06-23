#include "choose_torpedo_task.h"

uint8_t choose_flag = 0;
uint8_t counter = 0;
uint8_t torpedo_num;

void choose_task(void const * argument)
{
  while(1)
    {
			if (choose_flag == 1)
			{
				torpedo_num = counter;
				counter++;
				choose_flag = 2;
			}
			/*
			if(choose_flag == 3)
			{
				counter = 5;
				choose_flag = 4;
			}
			
			if (counter == 5 || counter == 9)
			{
				finish_flag = 1;
				choose_flag = 4;
			}
			*/
			osDelay(2);
    }
}
