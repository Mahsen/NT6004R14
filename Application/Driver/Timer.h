#ifndef __TIMER_H
#define __TIMER_H
#ifdef __cplusplus
extern "C" 
{
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define   TIMER_MAXCHANNELTIMER                            8
#define   TIMER_CHANNELOUTOFRANGE                          0xFF
//----------------------------------------------------------
void __init_Timer(void);

U8    TIMER_Add(U64 Period_ms, void (*Event) (void));
void  TIMER_SetEnable(U8 Channel, BIT Value);
void  TIMER_SetCount(U8 Channel, U64 Value);
U64   TIMER_GetCount(U8 Channel);
U32   CalculateCompareValue(U64 frequency);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif
#endif
