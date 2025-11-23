#include <REGX52.H>
#include "Car_Move.h"
#include "Delay.h"

//红外循迹引脚位定义 D1-4分别指代P1-4，代表从右往左四个红外循迹
sbit D1=P3^4;		
sbit D2=P3^5;
sbit D3=P3^6;
sbit D4=P3^7;

void Trace(void)
{
	if(D1==1&&D2==1&&D3==1&&D4==1)	//全检测到黑线
		{Car_Go(9);}
	if(D1==0&&D2==1&&D3==0&&D4==0)	//中间右侧检测到黑线，小车偏左，小车向右移动
	{
		Car_Right_Go(9);
		if(D1==0&&D2==0&&D3==0&&D4==0)
			{Car_Go(9);}
	}
	if(D1==0&&D2==0&&D3==1&&D4==0)	//中间左侧检测到黑线，小车偏右，小车向左移动
	{
		Car_Left_Go(9);
		if(D1==0&&D2==0&&D3==0&&D4==0)
			{Car_Go(9);}
	}
	if(D1==1&&D2==1&&D3==0&&D4==0)	//直角右拐
	{
		Car_Go(9);
		Delay(50);
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			Car_Stop();
			Delay(50);
			Car_Right_Stop(9);
		}
	}
	if(D1==0&&D2==0&&D3==1&&D4==1)	//直角左拐
	{
		Car_Go(9);
		Delay(50);
		if(D1==0&&D2==0&&D3==0&&D4==0)
		{
			Car_Stop();
			Delay(50);
			Car_Left_Stop(9);
		}
	}
}