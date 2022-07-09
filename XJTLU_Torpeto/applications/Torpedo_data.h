#ifndef TORPEDO_DATA_H
#define TORPEDO_DATA_H

#include "stm32f4xx_hal.h"
#include "struct_typedef.h"

//pitchƫ������С̧�ߣ����󽵵�
#define pitch_offset 	-200
//yawƫ�Ƽ�С������������
#define yaw_offset		-150

///////һ�ŷ��ڲ���//////(w)
#define Torpedo1_pitch 	0+pitch_offset
#define Torpedo1_yaw 		-250+yaw_offset
//#define Torpedo1_round 	1
#define Torpedo1_rank 	1

///////���ŷ��ڲ���//////(1)
#define Torpedo2_pitch 	0+pitch_offset
#define Torpedo2_yaw 		-350+yaw_offset
//#define Torpedo2_round 	1
#define Torpedo2_rank 	2

///////���ŷ��ڲ���//////(6)
#define Torpedo3_pitch 100+pitch_offset
#define Torpedo3_yaw 		-202+yaw_offset
//#define Torpedo3_round 	1
#define Torpedo3_rank 	3

///////�ĺŷ��ڲ���//////(1)
#define Torpedo4_pitch 	-100   +pitch_offset
#define Torpedo4_yaw 		-150+yaw_offset
//#define Torpedo4_round 	1
#define Torpedo4_rank 	4

///////��ŷ��ڲ���//////
#define Torpedo5_pitch 	-65+pitch_offset
#define Torpedo5_yaw 		-340+yaw_offset
//#define Torpedo5_round 	2
#define Torpedo5_rank 	5

///////���ŷ��ڲ���//////
#define Torpedo6_pitch 	-404+pitch_offset
#define Torpedo6_yaw 		-202+yaw_offset
//#define Torpedo6_round 	2
#define Torpedo6_rank 	6

///////�ߺŷ��ڲ���//////
#define Torpedo7_pitch 	604+pitch_offset
#define Torpedo7_yaw 		-288+yaw_offset
//#define Torpedo7_round 	2
#define Torpedo7_rank 	7

///////�˺ŷ��ڲ���//////
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
