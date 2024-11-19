/************************************************** Description *******************************************************/
/*
    File : Relay.c
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
#include "relay.h"
/************************************************** Defineds **********************************************************/
#define RELAY_GAS_DDR                                                           DDRA_DDA1
#define RELAY_GAS_PORT                                                          PORTA_PORTA1
#define RELAY_COM_DDR                                                           DDRC_DDC3
#define RELAY_COM_PORT                                                          PORTC_PORTC3
#define RELAY_LAMP_DDR                                                          DDRC_DDC2
#define RELAY_LAMP_PORT                                                         PORTC_PORTC2
#define RELAY_MOTOR_DDR                                                         DDRC_DDC1
#define RELAY_MOTOR_PORT                                                        PORTC_PORTC1
#define RELAY_FAN_DDR                                                           DDRC_DDC0
#define RELAY_FAN_PORT                                                          PORTC_PORTC0
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
void __init_Relay(void) {
  RELAY_GAS_DDR = OUTPUT;
  RELAY_GAS_PORT = RESET;
  
  RELAY_COM_DDR = OUTPUT;
  RELAY_COM_PORT = SET;
  
  RELAY_LAMP_DDR = OUTPUT;
  RELAY_LAMP_PORT = RESET;
  
  RELAY_MOTOR_DDR = OUTPUT;
  RELAY_MOTOR_PORT = RESET;
  
  RELAY_FAN_DDR = OUTPUT;
  RELAY_FAN_PORT = RESET;
}
/*--------------------------------------------------------------------------------------------------------------------*/
void Relay_Set(U8 Relay, BOOL Value) {
  switch(Relay) {
    case RELAY_GAS: {      
      RELAY_GAS_PORT = Value;
    }
    case RELAY_LAMP: {     
      RELAY_COM_PORT = !Value;
      RELAY_LAMP_PORT = Value;
    }
    case RELAY_MOTOR: {  
      RELAY_MOTOR_PORT = Value;
    }
    case RELAY_FAN: {      
      RELAY_FAN_PORT = Value;
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

