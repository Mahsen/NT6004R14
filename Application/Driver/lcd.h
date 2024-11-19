#ifndef __LCD_H
#define __LCD_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define LCD_COM_MAX                                10
  
#define LCD_DIGIT_LARGE                            0
#define LCD_DIGIT_SMALL                            1
  
#define LCD_ICONS_LIGHT                            ((U64(1)) << 0)
#define LCD_ICONS_WIFI                             ((U64(1)) << 1)
#define LCD_ICONS_MUSIC                            ((U64(1)) << 2)
#define LCD_ICONS_LOCK                             ((U64(1)) << 3)
#define LCD_ICONS_TIMER                            ((U64(1)) << 4)
#define LCD_ICONS_OVEN	                           ((U64(1)) << 5) 
#define LCD_ICONS_RING	                           ((U64(1)) << 6) 
#define LCD_ICONS_M_U	                           ((U64(1)) << 7) 
#define LCD_ICONS_M_D	                           ((U64(1)) << 8) 
#define LCD_ICONS_LAMP	                           ((U64(1)) << 9) 
#define LCD_ICONS_DEGRI                            ((U64(1)) << 10)
#define LCD_ICONS_DOT_U                            ((U64(1)) << 11)
#define LCD_ICONS_DOT_D                            ((U64(1)) << 12)
#define LCD_ICONS_1000	                           ((U64(1)) << 13) 
#define LCD_ICONS_FAN_0                            ((U64(1)) << 14)
#define LCD_ICONS_FAN_1                            ((U64(1)) << 15)
#define LCD_ICONS_FAN_2                            ((U64(1)) << 16)
#define LCD_ICONS_FAN_3                            ((U64(1)) << 17)
//----------------------------------------------------------
void __init_LCD(void);
void LCD_Icon_Set(U64 Icons, BOOL Value);
void LCD_String_Set(U8* String, U8 Digit);
void LCD_Refresh(void);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

