#include <REGX52.H>
#include "Car_Move.h"
#include "Delay.h"
#include "Intrins.h"
#include "Timer1.h"

sbit Trig=P2^6;		//超声波测距发射端位点
sbit Echo=P2^7;		//超声波测距接收端位点

unsigned int Distance;			//超声波测距结果
unsigned int MinDistance=20;	//小车与障碍物的限制距离 

void Delay20us(void)	//@11.0592MHz
{
	unsigned char data i;
	_nop_();
	i = 6;
	while (--i);
}

void Superaudible(void)
{
	TMOD = 0x11;
	TL1 = 0;		//设置定时初值
	TH1 = 0;		//设置定时初值
	Trig=1;			//发射一段脉冲，至少20us
	Delay20us();
	Trig=0;
	
	while(!Echo);	//等待超声波模块的返回脉冲
	TR1=1;			//打开定时器
	while(Echo);	//等待超声波模块返回脉冲结束
	TR1=0;			//关闭定时器，计时结束
	
	Distance=((TH1*256+TL1)*1.7)/100;		//计算距离  单位：cm
	if(Distance<MinDistance)
	{
		Car_Stop();
		Delay(1000);
	}	
	else
		Car_Go(9);
	
	
}



