/************************************************** Description *******************************************************/
/*
    File : Clock.c
    Programmer : Mohammad Lotfi
    Used : Manage lcd pinout
    Design Pattern : Nothing
    Types of memory : Nothing
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2024/11/19
*/
/************************************************** Warnings **********************************************************/
/*
    Nothing
*/
/************************************************** Wizards ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes **********************************************************/
#include "clock.h"
#include "timer.h"
#include "lcd.h"
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
/*
    Nothing
*/
/************************************************** Variables *********************************************************/
struct {
  U8 Hour;
  U8 Minute;
  U8 Second;
} Time[2];
U8 CLOCK_Mode = 0;
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
void __init_Clock(void) {
  TIMER_Add(1000, &CLOCK_Refresh);
}
/************************************************** Tasks *************************************************************/
void CLOCK_Machine(void) {
  static U8 Count = 0;
  if(Count++ > 10) {
    Count = 0;
    char str[5];
    if(CLOCK_Mode == 0) {      
      sprintf(str, "%02d%02d", Time[CLOCK_Mode].Hour, Time[CLOCK_Mode].Minute);
    }
    else {
      sprintf(str, "%02d%02d", Time[CLOCK_Mode].Minute, Time[CLOCK_Mode].Second);
    }
    LCD_String_Set((U8*)str, LCD_DIGIT_LARGE);
    static BOOL Blick = RESET;
    LCD_Icon_Set(LCD_ICONS_DOT_U, Blick);
    Blick ^= SET;
  }
}
/*--------------------------------------------------------------------------------------------------------------------*/
void CLOCK_SetMode(BOOL Mode) {
  if(Mode) {
    CLOCK_Mode = 1;
    Time[1].Hour = 0;
    Time[1].Minute = 0;
    Time[1].Second = 0;
  }
  else {
    CLOCK_Mode = 0;
  }
}
/************************************************** Vectors ***********************************************************/
void CLOCK_Refresh(void) {
  for(U8 Index=0; Index<2; Index++) {
    Time[Index].Second++;
    if(Time[Index].Second>59) {
      Time[Index].Second = 0;
      Time[Index].Minute++;
      if(Time[Index].Minute>59) {
        Time[Index].Minute = 0;
        Time[Index].Hour++;
        if(Time[Index].Minute>24) {
          Time[Index].Hour = 0;
        }
      }
    }
  }
}
/**********************************************************************************************************************/

