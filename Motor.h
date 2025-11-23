#ifndef __MOTOR_H__
#define __MOTOR_H__

//控制右前电机
void Motor_RF_go(unsigned char speed);			//右前电机正转
void Motor_RF_back(unsigned char speed);		//右前电机反转
void Motor_RF_stop(void);						//右前电机停止
//控制右后电机
void Motor_RR_go(unsigned char speed);			//右后电机正转
void Motor_RR_back(unsigned char speed);		//右后电机反转
void Motor_RR_stop(void);						//右后电机停止
//控制左前电机
void Motor_LF_go(unsigned char speed);			//左前电机正转
void Motor_LF_back(unsigned char speed);		//左前电机反转
void Motor_LF_stop(void);						//左前电机停止
//控制左后电机
void Motor_LR_go(unsigned char speed);			//左后电机正转
void Motor_LR_back(unsigned char speed);		//左后电机反转
void Motor_LR_stop(void);						//左后电机停止

#endif