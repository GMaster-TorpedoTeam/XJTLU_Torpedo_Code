#ifndef TORPEDO_DATA_H
#define TORPEDO_DATA_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

//pitch偏移量减小抬高，增大降低
#define pitch_offset 	-200
//yaw偏移减小往左，增大往右
#define yaw_offset		-150

///////一号飞镖参数//////(w)
#define Torpedo1_pitch 	0+pitch_offset
#define Torpedo1_yaw 		-250+yaw_offset
//#define Torpedo1_round 	1
#define Torpedo1_rank 	1

///////二号飞镖参数//////(1)
#define Torpedo2_pitch 	0+pitch_offset
#define Torpedo2_yaw 		-350+yaw_offset
//#define Torpedo2_round 	1
#define Torpedo2_rank 	2

///////三号飞镖参数//////(6)
#define Torpedo3_pitch 100+pitch_offset
#define Torpedo3_yaw 		-202+yaw_offset
//#define Torpedo3_round 	1
#define Torpedo3_rank 	3

///////四号飞镖参数//////(1)
#define Torpedo4_pitch 	-100   +pitch_offset
#define Torpedo4_yaw 		-150+yaw_offset
//#define Torpedo4_round 	1
#define Torpedo4_rank 	4

///////五号飞镖参数//////
#define Torpedo5_pitch 	-65+pitch_offset
#define Torpedo5_yaw 		-340+yaw_offset
//#define Torpedo5_round 	2
#define Torpedo5_rank 	5

///////六号飞镖参数//////
#define Torpedo6_pitch 	-404+pitch_offset
#define Torpedo6_yaw 		-202+yaw_offset
//#define Torpedo6_round 	2
#define Torpedo6_rank 	6

///////七号飞镖参数//////
#define Torpedo7_pitch 	604+pitch_offset
#define Torpedo7_yaw 		-288+yaw_offset
//#define Torpedo7_round 	2
#define Torpedo7_rank 	7

///////八号飞镖参数//////
#define Torpedo8_pitch 	299+pitch_offset
#define Torpedo8_yaw 		-480+yaw_offset
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
