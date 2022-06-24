#ifndef TORPEDO_DATA_H
#define TORPEDO_DATA_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

///////一号飞镖参数//////
#define Torpedo1_pitch 	-479
#define Torpedo1_yaw 		-380
//#define Torpedo1_round 	1
#define Torpedo1_rank 	1

///////二号飞镖参数//////
#define Torpedo2_pitch 	-395
#define Torpedo2_yaw 		31
//#define Torpedo2_round 	1
#define Torpedo2_rank 	2

///////三号飞镖参数//////
#define Torpedo3_pitch 	604
#define Torpedo3_yaw 		-288
//#define Torpedo3_round 	1
#define Torpedo3_rank 	3

///////四号飞镖参数//////
#define Torpedo4_pitch 	333
#define Torpedo4_yaw 		-421
//#define Torpedo4_round 	1
#define Torpedo4_rank 	4

///////五号飞镖参数//////
#define Torpedo5_pitch 	0
#define Torpedo5_yaw 		0
//#define Torpedo5_round 	2
#define Torpedo5_rank 	5

///////六号飞镖参数//////
#define Torpedo6_pitch 	1
#define Torpedo6_yaw 		0
//#define Torpedo6_round 	2
#define Torpedo6_rank 	6

///////七号飞镖参数//////
#define Torpedo7_pitch 	0
#define Torpedo7_yaw 		2
//#define Torpedo7_round 	2
#define Torpedo7_rank 	7

///////八号飞镖参数//////
#define Torpedo8_pitch 	0
#define Torpedo8_yaw 		0
//#define Torpedo8_round 	2
#define Torpedo8_rank 	8

#define Torpedo_number 	8


typedef __packed struct
{
	int pitch;
	int yaw;
	uint8_t rank;
	
} Torpedo_data_t;


void Torpedo_data_Init(void);

#endif
