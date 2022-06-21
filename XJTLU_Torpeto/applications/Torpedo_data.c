#include "Torpedo_data.h"



Torpedo_data_t torpedo_data[Torpedo_number];

int Torpedo_pitch[Torpedo_number] = {Torpedo1_pitch, Torpedo2_pitch, Torpedo3_pitch, Torpedo4_pitch, Torpedo5_pitch, Torpedo6_pitch,
	Torpedo7_pitch, Torpedo8_pitch};

int Torpedo_yaw[Torpedo_number] = {Torpedo1_yaw, Torpedo2_yaw, Torpedo3_yaw, Torpedo4_yaw, Torpedo5_yaw, Torpedo6_yaw, Torpedo7_yaw,
Torpedo8_yaw};

uint8_t Torpedo_rank[Torpedo_number] = {Torpedo1_rank, Torpedo2_rank, Torpedo3_rank, Torpedo4_rank, Torpedo5_rank, Torpedo6_rank, 
Torpedo7_rank, Torpedo8_rank};


//初始化飞镖参数
void Torpedo_data_Init(void)
{
	uint8_t i;
	
	for (i= 0; i < Torpedo_number ; i++ )
	{
		torpedo_data[i].pitch =  Torpedo_pitch[i];
		torpedo_data[i].yaw =  Torpedo_yaw[i];
	}
}
