#include <REGX52.H>
//#include "CAR_MOVE.h"
//#include "Delay.h"
//#include "Timer0.h"
//#include "Trace.h"
//#include "Superaudible.h"

sbit IN3=P1^2;		//右后电机，高电平正转
sbit IN4=P1^3;		//右后电机，高电平反转

void main()
{

//	Timer0_Init();	
//	Car_Go(20);	
	while(1)
	{
		IN3=1;
		IN4=0;
//		Superaudible();	
//		Trace();
		
		
	}
	


	
}

