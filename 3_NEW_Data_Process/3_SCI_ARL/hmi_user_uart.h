#ifndef _USER_UART__
#define _USER_UART__

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include  "std_init.h"
#define uchar    unsigned char
#define uint8    unsigned char
#define uint16   unsigned short int
#define uint32   unsigned long
#define int16    short int
#define int32    long

/****************************************************************************
* 名    称： UartInit()
* 功    能： SCIC串口初始化
* 入口参数： 无
* 出口参数： 无
****************************************************************************/
void UartInit(uint32 Baudrate);

/*****************************************************************
* 名    称： SendChar()
* 功    能： 发送1个字节
* 入口参数： t  发送的字节
* 出口参数： 无
 *****************************************************************/
void SendChar(uchar t);
void Send_msg(char *msg);
void SendValuetoLabview(LabView_Data* Test_LabviewData);

#endif
