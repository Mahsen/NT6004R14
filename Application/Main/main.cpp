/************************************************** Description *******************************************************/
/*
    File : main.cpp
    Programmer : Mohammad Lotfi
    Used : Nothing
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
#include "defines.h"
#include "gpio.h"
#include "relay.h"
#include "adc.h"
#include "switch.h"
#include "lcd.h"
#include "timer.h"
#include "clock.h"
#include "temp.h"
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
int main() {
  /* Initialize */
  __init_GPIO();
  __init_Relay();
  __init_ADC();
  __init_Switch();
  __init_LCD();
  __init_Timer();
  __init_Clock();
  __init_Temp();
  
  
  //GPIO_Buzzer_Set(true);
  //Relay_Set(RELAY_LAMP, RESET);
  //Relay_Set(RELAY_MOTOR, RESET);
  //Relay_Set(RELAY_FAN, RESET);
  
  /* Start Loop App */
  while(true) {
    
    CLOCK_Machine();
    TEMP_Machine();
    SWITCH_Machine();
    

    //LCD_Icon_Set(LCD_ICONS_WIFI, true);
    //DEFINE_Delay_s(1);
    //LCD_Icon_Set(LCD_ICONS_WIFI, false);
    //DEFINE_Delay_s(1);
    
//    char str[4];
//    static int num = 0;
//    sprintf(str, "%04d", Switch_Get());
//    LCD_String_Set((U8*)str, LCD_DIGIT_LARGE);
//    LCD_String_Set((U8*)"---", LCD_DIGIT_SMALL);
//    num++;
//    if(num >= 10) {
//      num = 0;
//    }
    
    DEFINE_Delay_ms(100);
  }

}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/

