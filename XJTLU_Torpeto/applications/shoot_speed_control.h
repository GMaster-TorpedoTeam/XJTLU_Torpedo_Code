#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H
#include "struct_typedef.h"
#include "remote_control.h"

extern RC_ctrl_t rc_ctrl;

static int last_speed;

void speed_set(void);
void s0(void);
void s1(void);
void speed_Limit(void);

void gear_max(void);
void gear_mid(void);
void gear_min(void);

#endif
