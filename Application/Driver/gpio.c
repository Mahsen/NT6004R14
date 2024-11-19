/************************************************** Description *******************************************************/
/*
    File : gpio.c
    Programmer : Mohammad Lotfi
    Used : Manage gpio pinout
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
#include "gpio.h"
/************************************************** Defineds **********************************************************/
#define GPIO_BUZZER_DDR                                                         DDRC_DDC7
#define GPIO_BUZZER_PORT                                                        PORTC_PORTC7
#define GPIO_LED_LEFT_DDR                                                       DDRA_DDA4
#define GPIO_LED_LEFT_PORT                                                      PORTA_PORTA4
#define GPIO_LED_UPDOWN_DDR                                                     DDRA_DDA0
#define GPIO_LED_UPDOWN_PORT                                                    PORTA_PORTA0
#define GPIO_LED_FAN_DDR                                                        DDRB_DDB0
#define GPIO_LED_FAN_PORT                                                       PORTB_PORTB0
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
void __init_GPIO(void) {
  GPIO_Disable_JTAG();
  
  GPIO_BUZZER_DDR = OUTPUT;
  GPIO_BUZZER_PORT = RESET;
  GPIO_LED_LEFT_DDR = OUTPUT;
  GPIO_LED_LEFT_PORT = RESET;
  GPIO_LED_UPDOWN_DDR = OUTPUT;
  GPIO_LED_UPDOWN_PORT = SET;
  GPIO_LED_FAN_DDR = OUTPUT;
  GPIO_LED_FAN_PORT = RESET;
}
/*--------------------------------------------------------------------------------------------------------------------*/
void GPIO_Disable_JTAG(void) {
    MCUCSR_JTD = SET;  // Write 1 to JTD
    MCUCSR_JTD = SET;  // Write 1 again within 4 cycles to disable JTAG
}
/*--------------------------------------------------------------------------------------------------------------------*/
void GPIO_Buzzer_Set(BOOL Value) {
  GPIO_BUZZER_PORT = Value;
}
/*--------------------------------------------------------------------------------------------------------------------*/
void GPIO_LED_Set(U8 led, BOOL Value) {
  switch(led) {
    case GPIO_LED_LEFT: {
      GPIO_LED_LEFT_PORT = Value;
      break;
    }    
    case GPIO_LED_UPDOWN: {
      GPIO_LED_UPDOWN_PORT = !Value;
      break;
    }
    case GPIO_LED_FAN: {
      GPIO_LED_UPDOWN_PORT = RESET;
      GPIO_LED_FAN_PORT = Value;
      break;
    }
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

