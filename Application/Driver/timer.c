/************************************************** Description *******************************************************/
/*
    File : timer.c
    Programmer : Mohammad Lotfi
    Used : timer
    Design Pattern : Nothing
    Types of memory : Nothing
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2024/9/13
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
#include "timer.h"
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
/*
    Nothing
*/
/************************************************** Variables *********************************************************/
struct struct_TIMER
{

  U8 Added;

  struct struct_Channel
  {
    BIT Enable;
    U64 Count;	
    U64 Period;
    void (*Event)(void);
  } Channel[TIMER_MAXCHANNELTIMER];
  	
} Timer;
/************************************************** Opjects ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions *********************************************************/
void __init_Timer(void)
{
    // Set Timer1 in CTC mode
    TCCR1B_WGM12 = SET;
    
    // Set prescaler to divide by 64
    TCCR1B_CS11 = SET;
    TCCR1B_CS10 = SET;
    
    // Set initial compare value for 1 ms interrupt
    OCR1A = CalculateCompareValue(1000); //18749;
    
    // Enable compare interrupt
    TIMSK_OCIE1A = SET;
    
    // Enable global interrupts
    __enable_interrupt();
}
/*--------------------------------------------------------------------------------------------------------------------*/
U32 CalculateCompareValue(U64 frequency)
{
    U64 clockFrequency = F_CPU;
    U64 prescaler = 64UL;
    U64 compareValue = (clockFrequency / (prescaler * frequency));
    
    return (U32)compareValue;
}
/*--------------------------------------------------------------------------------------------------------------------*/
U8 TIMER_Add(U64 Period_ms, void (*Event) (void))
{
  /// Check max Channel Timer
  if(Timer.Added<TIMER_MAXCHANNELTIMER)
  {		
    __disable_interrupt();
    Timer.Channel[Timer.Added].Count = RESET;
    Timer.Channel[Timer.Added].Period = Period_ms;
    Timer.Channel[Timer.Added].Event = Event;
    
    Timer.Channel[Timer.Added].Enable = ENABLE;
    Timer.Added++;
  }
  else
  {
    __enable_interrupt();
    return TIMER_CHANNELOUTOFRANGE;
  }

  __enable_interrupt();
  return (Timer.Added-1);
}
/*--------------------------------------------------------------------------------------------------------------------*/
void  TIMER_SetEnable(U8 Channel, BIT Value)
{
  if(Channel<Timer.Added)
  {
    Timer.Channel[Channel].Enable = Value;						
  }
}
/*--------------------------------------------------------------------------------------------------------------------*/
void  TIMER_SetCount(U8 Channel, U64 Count)
{
  if(Channel<Timer.Added)
  {
    if(Timer.Channel[Channel].Enable)
    {
      Timer.Channel[Channel].Count = Count;
    }	
  }	
}
/*--------------------------------------------------------------------------------------------------------------------*/
U64  TIMER_GetCount(U8 Channel)
{
  if(Channel<Timer.Added)
  {
    if(Timer.Channel[Channel].Enable)
    {
      return Timer.Channel[Channel].Count;				
    }	
  }

  return RESET;
}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
// IAR C interrupt  handler
#pragma vector=TIMER1_COMPA_vect
__interrupt void TIMER1_COMPA_ISR(void)
{
    for(U8 Index=RESET; Index<Timer.Added; Index++)
    {
        if(Timer.Channel[Index].Enable)
        {
            if(Timer.Channel[Index].Count < 0xFFFFFFFFFFFFFFFF)
            {
                Timer.Channel[Index].Count++;
            }				
            if(Timer.Channel[Index].Period)
            {
                if(Timer.Channel[Index].Event)
                {
                    if(Timer.Channel[Index].Count >= Timer.Channel[Index].Period)
                    {
                        Timer.Channel[Index].Count = RESET;
                        (*Timer.Channel[Index].Event)();
                    }
                }
            }		
        }
    }
}
/**********************************************************************************************************************/

