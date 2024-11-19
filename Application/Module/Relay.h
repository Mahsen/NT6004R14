#ifndef __RELAY_H
#define __RELAY_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define RELAY_GAS                                         0
#define RELAY_LAMP                                        1
#define RELAY_MOTOR                                       2
#define RELAY_FAN                                         3                                  
//----------------------------------------------------------
void __init_Relay(void);
void Relay_Set(U8 Relay, BOOL Value);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

