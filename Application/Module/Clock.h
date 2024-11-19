#ifndef __CLOCK_H
#define __CLOCK_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
void __init_Clock(void);
void CLOCK_SetMode(BOOL Mode);
void CLOCK_Machine(void);
void CLOCK_Refresh(void);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

