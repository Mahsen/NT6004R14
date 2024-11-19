/************************************************** Description *******************************************************/
/*
    File : adc.c
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
#include "adc.h"
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
void __init_ADC(void) {
    // 1. Set the reference voltage to AVCC (5V) and select channel 0 (initially)
    ADMUX_REFS0 = SET; // REFS0 = 1, REFS1 = 0 -> AVCC with external capacitor on AREF pin

    // 2. Enable the ADC and set the prescaler to 64
    // Prescaler = F_CPU / ADC_Clock (ADC clock must be between 50 kHz and 200 kHz)
    // ADPS2:0 = 110 (Prescaler = 64)
    ADCSRA_ADEN = SET;
    ADCSRA_ADPS2 = SET;
    ADCSRA_ADPS1 = SET; 
}
/*--------------------------------------------------------------------------------------------------------------------*/
U16 ADC_Read(U8 Channel) {
    // 1. Select the ADC channel (0-7) by clearing MUX bits in ADMUX
    ADMUX = (ADMUX & 0xF0) | (Channel & 0x07); // Clear old channel, set new channel

    // 2. Start the ADC conversion
    ADCSRA_ADSC = SET; // ADSC = 1 -> Start Conversion

    // 3. Wait for the conversion to complete (ADIF will be set)
    while (ADCSRA_ADSC); // Wait until ADSC becomes 0 (Conversion Complete)

    // 4. Read and return the ADC result (10 bits)
    return ADC; // Combined ADCL and ADCH registers
}
/*--------------------------------------------------------------------------------------------------------------------*/
U16 ADC_Read_Average(U8 Channel) {
    U16 Value = 0;
    for(U8 Index=0; Index<10; Index++) {
      Value += ADC_Read(Channel);
    }
    return (Value/10); 
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

