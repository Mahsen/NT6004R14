#ifndef __SWITCH_H
#define __SWITCH_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define SWITCH_KEY_NOTHING                               0
#define SWITCH_KEY_ALARM                                 1
#define SWITCH_KEY_CLOCK                                 2
#define SWITCH_KEY_AUTOOFF                               3                                  
#define SWITCH_KEY_LAMP_DOWN                             4
#define SWITCH_KEY_MOTOR_UP                              5
#define SWITCH_KEY_LOCK_FAN                              6
//----------------------------------------------------------
void __init_Switch(void);
U8 SWITCH_Get(void);
void SWITCH_Machine(void);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

