#ifndef __ADC_H
#define __ADC_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
#define ADC_KEY_L	                           5
#define ADC_KEY_R	                           2
#define ADC_TEMP	                           3
//----------------------------------------------------------
void __init_ADC(void);
U16 ADC_Read(U8 Channel);
U16 ADC_Read_Average(U8 Channel);
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

