/************************************************** Description *******************************************************/
/*
    File : lcd.c
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
#include "lcd.h"
#include "timer.h"
/************************************************** Defineds **********************************************************/
#define LCD_COM_1_DDR                                                           DDRB_DDB1
#define LCD_COM_1_PORT                                                          PORTB_PORTB1
#define LCD_COM_2_DDR                                                           DDRB_DDB2
#define LCD_COM_2_PORT                                                          PORTB_PORTB2
#define LCD_COM_3_DDR                                                           DDRB_DDB3
#define LCD_COM_3_PORT                                                          PORTB_PORTB3
#define LCD_COM_4_DDR                                                           DDRD_DDD2
#define LCD_COM_4_PORT                                                          PORTD_PORTD2
#define LCD_COM_5_DDR                                                           DDRD_DDD1
#define LCD_COM_5_PORT                                                          PORTD_PORTD1
#define LCD_COM_6_DDR                                                           DDRD_DDD0
#define LCD_COM_6_PORT                                                          PORTD_PORTD0
#define LCD_COM_7_DDR                                                           DDRB_DDB7
#define LCD_COM_7_PORT                                                          PORTB_PORTB7
#define LCD_COM_8_DDR                                                           DDRB_DDB6
#define LCD_COM_8_PORT                                                          PORTB_PORTB6
#define LCD_COM_9_DDR                                                           DDRB_DDB5
#define LCD_COM_9_PORT                                                          PORTB_PORTB5
#define LCD_COM_10_DDR                                                          DDRB_DDB4
#define LCD_COM_10_PORT                                                         PORTB_PORTB4

#define LCD_SEG_1_DDR                                                           DDRC_DDC1
#define LCD_SEG_1_PORT                                                          PORTC_PORTC1
#define LCD_SEG_2_DDR                                                           DDRC_DDC0
#define LCD_SEG_2_PORT                                                          PORTC_PORTC0
#define LCD_SEG_3_DDR                                                           DDRD_DDD7
#define LCD_SEG_3_PORT                                                          PORTD_PORTD7
#define LCD_SEG_4_DDR                                                           DDRD_DDD6
#define LCD_SEG_4_PORT                                                          PORTD_PORTD6
#define LCD_SEG_5_DDR                                                           DDRD_DDD5
#define LCD_SEG_5_PORT                                                          PORTD_PORTD5
#define LCD_SEG_6_DDR                                                           DDRD_DDD4
#define LCD_SEG_6_PORT                                                          PORTD_PORTD4
#define LCD_SEG_7_DDR                                                           DDRD_DDD3
#define LCD_SEG_7_PORT                                                          PORTD_PORTD3
/************************************************** Names *************************************************************/
/*
    Nothing
*/
/************************************************** Variables *********************************************************/
volatile U64 LCD_Icons = 0;
volatile U8 LCD_Digit_Large[4] = {'0', '0', '0', '0'};
volatile U8 LCD_Digit_Small[3] = {'0', '0', '0'};
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
void __init_LCD(void) {
  LCD_COM_1_DDR = OUTPUT;
  LCD_COM_1_PORT = RESET;
  LCD_COM_2_DDR = OUTPUT;
  LCD_COM_2_PORT = RESET;
  LCD_COM_3_DDR = OUTPUT;
  LCD_COM_3_PORT = RESET;
  LCD_COM_4_DDR = OUTPUT;
  LCD_COM_4_PORT = RESET;
  LCD_COM_5_DDR = OUTPUT;
  LCD_COM_5_PORT = RESET;
  LCD_COM_6_DDR = OUTPUT;
  LCD_COM_6_PORT = RESET;
  LCD_COM_7_DDR = OUTPUT;
  LCD_COM_7_PORT = RESET;
  LCD_COM_8_DDR = OUTPUT;
  LCD_COM_8_PORT = RESET;
  LCD_COM_9_DDR = OUTPUT;
  LCD_COM_9_PORT = RESET;
  LCD_COM_10_DDR = OUTPUT;
  LCD_COM_10_PORT = RESET;
  
  LCD_SEG_1_DDR = OUTPUT;
  LCD_SEG_1_PORT = SET;
  LCD_SEG_2_DDR = OUTPUT;
  LCD_SEG_2_PORT = SET;
  LCD_SEG_3_DDR = OUTPUT;
  LCD_SEG_3_PORT = SET;
  LCD_SEG_4_DDR = OUTPUT;
  LCD_SEG_4_PORT = SET;
  LCD_SEG_5_DDR = OUTPUT;
  LCD_SEG_5_PORT = SET;
  LCD_SEG_6_DDR = OUTPUT;
  LCD_SEG_6_PORT = SET;
  LCD_SEG_7_DDR = OUTPUT;
  LCD_SEG_7_PORT = SET;
  
  TIMER_Add(1, &LCD_Refresh);
}
/*--------------------------------------------------------------------------------------------------------------------*/
void LCD_Icon_Set(U64 Icons, BOOL Value) {
  for(U64 Index=0; Index<64; Index++) {
    if((Icons >> Index)&1) {
      if(Value) {
        LCD_Icons |= ((U64(1)) << Index);
      }
      else {
        LCD_Icons &= ~((U64(1)) << Index);
      }
    }
  }
}
/*--------------------------------------------------------------------------------------------------------------------*/
void LCD_String_Set(U8* String, U8 Digit) {
  if(Digit == LCD_DIGIT_LARGE) {
    memcpy((void*)LCD_Digit_Large, String, 4);
  }
  else {
    memcpy((void*)LCD_Digit_Small, String, 3);
  }
}
/*--------------------------------------------------------------------------------------------------------------------*/
void LCD_SetSegment(U8 Digit) {
  switch(Digit) {
    case '0': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = RESET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = SET;
      break;
    }
    case '1': {
      LCD_SEG_1_PORT = SET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = SET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = SET;
      break;
    }
    case '2': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = SET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = RESET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '3': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '4': {
      LCD_SEG_1_PORT = SET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = SET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '5': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = SET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '6': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = SET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = RESET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '7': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = SET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = SET;
      break;
    }
    case '8': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = RESET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '9': {
      LCD_SEG_1_PORT = RESET;
      LCD_SEG_2_PORT = RESET;
      LCD_SEG_3_PORT = RESET;
      LCD_SEG_4_PORT = RESET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = RESET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    case '-': {
      LCD_SEG_1_PORT = SET;
      LCD_SEG_2_PORT = SET;
      LCD_SEG_3_PORT = SET;
      LCD_SEG_4_PORT = SET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = RESET;
      break;
    }
    default: {
      LCD_SEG_1_PORT = SET;
      LCD_SEG_2_PORT = SET;
      LCD_SEG_3_PORT = SET;
      LCD_SEG_4_PORT = SET;
      LCD_SEG_5_PORT = SET;
      LCD_SEG_6_PORT = SET;
      LCD_SEG_7_PORT = SET;
    }        
  }
}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
void LCD_Refresh(void) {
  static int COM = 0;
  switch(COM) {
    /* COM 1 */
    case 0: {      
      if(LCD_Icons & LCD_ICONS_LIGHT) {
        LCD_SEG_4_PORT = RESET;
      }
      else {
        LCD_SEG_4_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_WIFI) {
        LCD_SEG_1_PORT = RESET;
      }
      else {
        LCD_SEG_1_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_MUSIC) {
        LCD_SEG_2_PORT = RESET;
      }
      else {
        LCD_SEG_2_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_LOCK) {
        LCD_SEG_3_PORT = RESET;
      }
      else {
        LCD_SEG_3_PORT = SET;
      }
      LCD_COM_1_PORT = SET;  
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 2 */
    case 1: {     
      if(LCD_Icons & LCD_ICONS_TIMER) {
        LCD_SEG_5_PORT = RESET;
      }
      else {
        LCD_SEG_5_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_OVEN) {
        LCD_SEG_6_PORT = RESET;
      }
      else {
        LCD_SEG_6_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_RING) {
        LCD_SEG_7_PORT = RESET;
      }
      else {
        LCD_SEG_7_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_M_U) {
        LCD_SEG_2_PORT = RESET;
      }
      else {
        LCD_SEG_2_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_M_D) {
        LCD_SEG_3_PORT = RESET;
      }
      else {
        LCD_SEG_3_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_LAMP) {
        LCD_SEG_4_PORT = RESET;
      }
      else {
        LCD_SEG_4_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_DEGRI) {
        LCD_SEG_1_PORT = RESET;
      }
      else {
        LCD_SEG_1_PORT = SET;
      }
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = SET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 3 */
    case 2: {      
      if(LCD_Icons & LCD_ICONS_DOT_U) {
        LCD_SEG_5_PORT = RESET;
      }
      else {
        LCD_SEG_5_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_DOT_D) {
        LCD_SEG_6_PORT = RESET;
      }
      else {
        LCD_SEG_6_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_1000) {
        LCD_SEG_7_PORT = RESET;
      }
      else {
        LCD_SEG_7_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_FAN_0) {
        LCD_SEG_1_PORT = RESET;
      }
      else {
        LCD_SEG_1_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_FAN_1) {
        LCD_SEG_2_PORT = RESET;
      }
      else {
        LCD_SEG_2_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_FAN_2) {
        LCD_SEG_3_PORT = RESET;
      }
      else {
        LCD_SEG_3_PORT = SET;
      }
      if(LCD_Icons & LCD_ICONS_FAN_3) {
        LCD_SEG_4_PORT = RESET;
      }
      else {
        LCD_SEG_4_PORT = SET;
      }
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = SET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 4 */
    case 3: {      
      LCD_SetSegment(LCD_Digit_Large[0]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = SET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 5 */
    case 4: {      
      LCD_SetSegment(LCD_Digit_Large[1]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = SET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 6 */
    case 5: {      
      LCD_SetSegment(LCD_Digit_Large[2]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = SET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 7 */
    case 6: {      
      LCD_SetSegment(LCD_Digit_Large[3]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = SET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 8 */
    case 7: {      
      LCD_SetSegment(LCD_Digit_Small[0]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = SET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 9 */
    case 8: {      
      LCD_SetSegment(LCD_Digit_Small[1]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = SET;
      LCD_COM_10_PORT = RESET;
      break;
    }
    /* COM 10 */
    case 9: {      
      LCD_SetSegment(LCD_Digit_Small[2]);      
      LCD_COM_1_PORT = RESET;
      LCD_COM_2_PORT = RESET;
      LCD_COM_3_PORT = RESET;
      LCD_COM_4_PORT = RESET;
      LCD_COM_5_PORT = RESET;
      LCD_COM_6_PORT = RESET;
      LCD_COM_7_PORT = RESET;
      LCD_COM_8_PORT = RESET;
      LCD_COM_9_PORT = RESET;
      LCD_COM_10_PORT = SET;
      break;
    }
  }
  if(COM < LCD_COM_MAX) {
    COM++;
  }
  else {
    COM = 0;
  }
}
/**********************************************************************************************************************/

