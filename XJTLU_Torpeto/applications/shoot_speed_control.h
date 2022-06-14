#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H
#include "struct_typedef.h"
#include "remote_control.h"

extern RC_ctrl_t rc_ctrl;

void shoot_speed_limit(void);
void shoot_motor_speed(void);

void push_motor_speed(void);

#endif
