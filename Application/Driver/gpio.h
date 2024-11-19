#ifndef __GPIO_H
#define __GPIO_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define GPIO_LED_LEFT                                      0  
#define GPIO_LED_UPDOWN                                    1
#define GPIO_LED_FAN                                       2
//----------------------------------------------------------
void __init_GPIO(void);
void GPIO_Disable_JTAG(void);
void GPIO_Buzzer_Set(BOOL Value);
void GPIO_LED_Set(U8 led, BOOL Value);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

