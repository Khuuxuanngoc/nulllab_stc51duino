//----------------------------------------------------------------
// stc firm lib
// for stc12c56xx
// uart.c
// by flotox@yeah.net
// http://hi.baidu.com/flotox
// 2011-07-14
// for arduino by huaweiwx@sina.com 2018.5.19
//----------------------------------------------------------------

#include"Arduino.h"

/*��BRC.exe���ɵĲ��������ú���(ֻ�����ù�����ģʽ1��3�µĲ�����),Ĭ���������,���Ϊ��ʽ0��ʽ2�����Լ���д*/
/*���uart������ģʽ0��ģʽ2,��ʱ���Բ�ռ�ö�ʱ��*/
void uart_init0(unsigned long baud)
{
    SCON = 0x50;            //8-bit variable UART
    TMOD = 0x20;            //Set Timer1 as 8-bit auto reload mode
    TH1 = TL1 = -(F_CPU/12/32/baud); //Set auto-reload vaule
    TR1 = 1;                //Timer1 start run
    ES = 1;                 //Enable UART interrupt
    EA = 1;                 //Open master interrupt switch
}
