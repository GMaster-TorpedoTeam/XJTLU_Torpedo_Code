#include "referee_send_task.h"

void referee_send_task(void const * argument)
{
  while(1)
    {
			if (referee_state == 1)
			{
				Command_send();
			}
    }
}
