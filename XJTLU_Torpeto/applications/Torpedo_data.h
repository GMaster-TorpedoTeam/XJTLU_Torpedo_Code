#ifndef TORPEDO_DATA_H
#define TORPEDO_DATA_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

///////һ�ŷ��ڲ���//////
#define Torpedo1_pitch 	80
#define Torpedo1_yaw 		-150
//#define Torpedo1_round 	1
#define Torpedo1_rank 	1

///////���ŷ��ڲ���//////
#define Torpedo2_pitch 	0
#define Torpedo2_yaw 		0
//#define Torpedo2_round 	1
#define Torpedo2_rank 	2

///////���ŷ��ڲ���//////
#define Torpedo3_pitch 	0
#define Torpedo3_yaw 		0
//#define Torpedo3_round 	1
#define Torpedo3_rank 	3

///////�ĺŷ��ڲ���//////
#define Torpedo4_pitch 	0
#define Torpedo4_yaw 		0
//#define Torpedo4_round 	1
#define Torpedo4_rank 	4

///////��ŷ��ڲ���//////
#define Torpedo5_pitch 	0
#define Torpedo5_yaw 		0
//#define Torpedo5_round 	2
#define Torpedo5_rank 	5

///////���ŷ��ڲ���//////
#define Torpedo6_pitch 	1
#define Torpedo6_yaw 		0
//#define Torpedo6_round 	2
#define Torpedo6_rank 	6

///////�ߺŷ��ڲ���//////
#define Torpedo7_pitch 	0
#define Torpedo7_yaw 		2
//#define Torpedo7_round 	2
#define Torpedo7_rank 	7

///////�˺ŷ��ڲ���//////
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
