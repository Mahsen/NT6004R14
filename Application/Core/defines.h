#ifndef __DEFINES_H
#define __DEFINES_H
#ifdef __cplusplus
extern "C" {
#endif
//----------------------------------------------------------
#include <intrinsics.h>
#include <iom32.h>
#include <ioavr.h>
#include <string.h>
#include <stdio.h>
//----------------------------------------------------------
#ifndef F_CPU
#define F_CPU 12000000UL
#endif
  
#define     C_UNIC              * 1
//----------------------------------------------------------
#define     NULL_CHAR           0x00
#define     CR_CHAR             0x0D
#define     LF_CHAR             0x0A
#define     ACK_CHAR            0x06
#define     CTRLZ_CHAR          0x1A
#define     DEL_CHAR            0x7F
#define     SOH_CHAR            0x01
#define     STX_CHAR            0x02
#define     ETX_CHAR            0x03
#define     EOT_CHAR            0x04
#define     NAK_CHAR            0x15
//----------------------------------------------------------
typedef signed char     S8;
typedef unsigned char   U8;
typedef short           S16;
typedef unsigned short  U16;
typedef int             S32;
typedef unsigned int    U32;
typedef long long       S64;
typedef unsigned long long U64;
typedef unsigned char   BIT;
typedef unsigned int    BOOL;
//----------------------------------------------------------
//	#ifndef TRUE
//		#define   TRUE               1
//	#endif
//	#ifndef TRUE
//		#define   FALSE              0
//	#endif
	#ifndef SET
		#define   SET                1
	#endif
	#ifndef RESET
		#define   RESET              0
	#endif
	#ifndef OUTPUT
		#define   OUTPUT             1
	#endif
	#ifndef INPUT
		#define   INPUT              0
	#endif
	#ifndef ENABLE
		#define   ENABLE             1
	#endif
	#ifndef DISABLE
		#define   DISABLE            0
	#endif
//	#ifndef UP
//		#define   UP                 1
//	#endif
//----------------------------------------------------------
typedef void (*CallBack_Type)(void);
//----------------------------------------------------------
#define USec                                *1
#define MSec   				    *1000
#define Sec                         	    *1000000
//----------------------------------------------------------
U8 DEFINE_Ascii2Hex(U8 Convert);
U8* DEFINE_itoa(U64 Value, U8* Length);
void DEFINE_Delay(U32 USecond);
void DEFINE_Delay_ms(U32 MSecond);
//----------------------------------------------------------
#define DEFINE_WAIT(VALUE,TIME_ms)  for(U32 DEFINE_Time = RESET; ((DEFINE_Time<TIME_ms)&&(VALUE)); DEFINE_Time++){DEFINE_Delay(1 MSec);}
//----------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

