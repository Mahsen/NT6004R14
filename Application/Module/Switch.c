/************************************************** Description *******************************************************/
/*
    File : Switch.c
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
#include "switch.h"
#include "adc.h"
#include "relay.h"
#include "lcd.h"
#include "clock.h"
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
/*
    Nothing
*/
/************************************************** Variables *********************************************************/
/*
    Nothing
*/
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
void __init_Switch(void) {

}
/*--------------------------------------------------------------------------------------------------------------------*/
U8 SWITCH_Get(void) {
  U16 ADC_KEY_Left_Value = ADC_Read_Average(ADC_KEY_L);
  U16 ADC_KEY_Right_Value = ADC_Read_Average(ADC_KEY_R);
  if(ADC_KEY_Left_Value < 300) {
    return SWITCH_KEY_ALARM;
  }
  else if(ADC_KEY_Left_Value < 500) {
    return SWITCH_KEY_CLOCK;
  }
  else if(ADC_KEY_Left_Value < 800) {
    return SWITCH_KEY_AUTOOFF;
  }
  if(ADC_KEY_Right_Value < 300) {
    return SWITCH_KEY_LAMP_DOWN;
  }
  else if(ADC_KEY_Right_Value < 500) {
    return SWITCH_KEY_MOTOR_UP;
  }
  else if(ADC_KEY_Right_Value < 800) {
    return SWITCH_KEY_LOCK_FAN;
  }
  
  return SWITCH_KEY_NOTHING;
}
/************************************************** Tasks *************************************************************/
void SWITCH_Machine(void) {
  static U8 Count;
  static BOOL FAN = RESET;
  if(Count++ > 10) {
    Count = 0;
    static U8 Key_Feed = 0;
    U8 Key = SWITCH_Get();
    if(Key != Key_Feed) {
      Key_Feed = Key;
      switch(Key) {
        case SWITCH_KEY_CLOCK: {
          static BOOL CLOCK = SET;
          CLOCK_SetMode(CLOCK);
          LCD_Icon_Set(LCD_ICONS_TIMER, CLOCK);
          CLOCK ^= SET;
          break;
        }     
        case SWITCH_KEY_AUTOOFF: {
          static BOOL AUTOOFF = SET;
          Relay_Set(RELAY_GAS, AUTOOFF);
          LCD_Icon_Set(LCD_ICONS_OVEN, AUTOOFF);
          AUTOOFF ^= SET;
          break;
        } 
        case SWITCH_KEY_LAMP_DOWN: {
          static BOOL LAMP = SET;
          Relay_Set(RELAY_LAMP, LAMP);
          LCD_Icon_Set(LCD_ICONS_LAMP, LAMP);
          LAMP ^= SET;
          break;
        }
        case SWITCH_KEY_MOTOR_UP: {
          static BOOL MOTOR = SET;
          Relay_Set(RELAY_MOTOR, MOTOR);
          LCD_Icon_Set(LCD_ICONS_M_U | LCD_ICONS_M_D, MOTOR);
          MOTOR ^= SET;
          break;
        }
        case SWITCH_KEY_LOCK_FAN: {
          FAN ^= SET;
          Relay_Set(RELAY_FAN, FAN);   
          if(FAN == RESET) {
            LCD_Icon_Set(LCD_ICONS_FAN_0 | LCD_ICONS_FAN_1 | LCD_ICONS_FAN_2 | LCD_ICONS_FAN_3, RESET);
          }
          else {
            LCD_Icon_Set(LCD_ICONS_FAN_0, SET);
          }
          break;
        }
      }
    }
  }
  if(FAN) {
    static U8 FAN_Count = 0;
    FAN_Count++;
    if(FAN_Count==1) {
      LCD_Icon_Set(LCD_ICONS_FAN_2 | LCD_ICONS_FAN_3, RESET);
      LCD_Icon_Set(LCD_ICONS_FAN_1, SET);
    }
    else if(FAN_Count==2) {
      LCD_Icon_Set(LCD_ICONS_FAN_1 | LCD_ICONS_FAN_3, RESET);
      LCD_Icon_Set(LCD_ICONS_FAN_2, SET);
    }
    else if(FAN_Count==3) {
      LCD_Icon_Set(LCD_ICONS_FAN_1 | LCD_ICONS_FAN_2, RESET);
      LCD_Icon_Set(LCD_ICONS_FAN_3, SET);
      FAN_Count = 0;
    }      
  }
}
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/

