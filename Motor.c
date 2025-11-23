/*电机正反转*/
/*
LF左前  LR左后   RF右前   RR右后
*/
/*电机正反转*/
#include <REGX52.H>
#include "Timer0.h"

sbit IN1=P1^0;		//右前电机，高电平正转
sbit IN2=P1^1;		//右前电机，高电平反转
sbit IN3=P1^2;		//右后电机，高电平正转
sbit IN4=P1^3;		//右后电机，高电平反转
sbit IN5=P1^4;		//左前电机，高电平正转
sbit IN6=P1^5;		//左前电机，高电平反转
sbit IN7=P1^6;		//左后电机，高电平正转
sbit IN8=P1^7;		//左后电机，高电平反转
sbit EN1=P2^5;		//右电机使能开关
sbit EN2=P2^5;
sbit EN3=P2^4;		//左电机使能开关
sbit EN4=P2^4;

unsigned char Counter,Speed_right,Speed_left;		//Counter:计数值（0-20）  Speed:电机速度调节（0-20）建议至少从8开始


// 以下函数的输入参数speed均为通过控制Speed来调节电机速度

//控制右前电机
void Motor_RF_go(unsigned char speed)		//右前电机正转
{Speed_right=speed;IN1=1;IN2=0;}

void Motor_RF_back(unsigned char speed)		//右前电机反转
{Speed_right=speed;IN1=0;IN2=1;}

void Motor_RF_stop(void)					//右前电机停止
{IN1=0;IN2=0;}


//控制右后电机
void Motor_RR_go(unsigned char speed)		//右后电机正转
{Speed_right=speed;IN3=1;IN4=0;}

void Motor_RR_back(unsigned char speed)		//右后电机反转
{Speed_right=speed;IN3=0;IN4=1;}

void Motor_RR_stop(void)					//右后电机停止
{IN3=0;IN4=0;}


//控制左前电机
void Motor_LF_go(unsigned char speed)		//左前电机正转
{Speed_left=speed;IN5=1;IN6=0;}

void Motor_LF_back(unsigned char speed)		//左前电机反转
{Speed_left=speed;IN5=0;IN6=1;}

void Motor_LF_stop(void)					//左前电机停止
{IN5=0;IN6=0;}


//控制左后电机
void Motor_LR_go(unsigned char speed)		//左后电机正转
{Speed_left=speed;IN7=1;IN8=0;}

void Motor_LR_back(unsigned char speed)		//左后电机反转
{Speed_left=speed;IN7=0;IN8=1;}

void Motor_LR_stop(void)					//左后电机停止
{IN7=0;IN8=0;}




void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	Counter++;
	Counter%=20;	//计数值变化范围限制在0~19
	if(Counter<Speed_right)	//计数值小于比较值
	{
		EN1=1;		//右电机使能
	
	}
	else				//计数值大于比较值
	{
		EN1=0;		//右电机不使能			
	}
	if(Counter<Speed_left)	//计数值小于比较值
	{
		EN3=1;		//左电机使能
	
	}
	else				//计数值大于比较值
	{
		EN3=0;		//左电机不使能			
	}
	
	
}