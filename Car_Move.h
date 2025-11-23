#ifndef __CAR_MOVE_H__
#define __CAR_MOVE_H__


void Car_Go(unsigned char speed);		//通过控制电机来控制小车前进
void Car_Back(unsigned char speed);		//通过控制电机来控制小车后退
void Car_Stop(void);					//通过控制电机来控制小车停止
void Car_Left_Go(unsigned char speed);				//通过控制电机来控制小车前进左转
void Car_Right_Go(unsigned char speed);				//通过控制电机来控制小车前进右转
void Car_Left_Back(unsigned char speed);//通过控制电机来控制小车后退左转
void Car_Right_Back(unsigned char speed);//通过控制电机来控制小车后退右转
void Car_Left_Stop(unsigned char speed);//通过控制电机来控制小车原地左转
void Car_Right_Stop(unsigned char speed);//通过控制电机来控制小车原地右转



#endif