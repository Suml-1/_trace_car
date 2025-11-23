/*小车运动方向*/
/*
向前直行 四电机正转
向后直行 四电机反转
向前左拐 右电机正转，左电机停止或反转
向前右拐 左电机正转，右电机停止或反转
向后左拐 右电机反转，左电机停止或正转
向后右拐 左电机反转，右电机停止或正转
停    止 四电机停止
*/
/*小车运动方向*/


#include <REGX52.H>
#include "Motor.h"

/*
!!!!!!!!!!!!!!!!!
关于以下函数的形参speed
通过小车的speed控制电机的速度
motor模块函数默认值为小车模块函数输入值，
可对其值进行修改调试，
以更好驱动小车转弯。  
!!!!!!!!!!!!!!!!!
*/

/**
  * @brief  通过控制电机来控制小车前进
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Go(unsigned char speed)
{
	Motor_RF_go(speed-1);		//右前电机正转
	Motor_LF_go(speed);			//左前电机正转
	Motor_LR_go(speed);			//左后电机正转	
	Motor_RR_go(speed-1);		//右后电机正转	
}


/**
  * @brief  通过控制电机来控制小车后退
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Back(unsigned char speed)
{
	Motor_RF_back(speed);		//右前电机反转
	Motor_LF_back(speed);		//左前电机反转
	Motor_LR_back(speed);		//左后电机反转	
	Motor_RR_back(speed);		//右后电机反转
}

/**
  * @brief  通过控制电机来控制小车停止
  * @param  无
  * @retval 无
  */
void Car_Stop(void)
{
	Motor_RF_stop();			//右前电机停止
	Motor_LF_stop();			//左前电机停止
	Motor_LR_stop();			//左后电机停止
	Motor_RR_stop();			//右后电机停止	
}



/**
  * @brief  通过控制电机来控制小车前进左转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Left_Go(unsigned char speed)
{
	Motor_RF_go(speed);			//右前电机正转
	Motor_RR_go(speed);			//右后电机正转
	Motor_LF_stop();			//左前电机停止
	Motor_LR_stop();			//左后电机停止	
}


/**
  * @brief  通过控制电机来控制小车前进右转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Right_Go(unsigned char speed)
{
	Motor_LF_go(speed);			//左前电机正转
	Motor_LR_go(speed);			//左后电机正转
	Motor_RF_stop();			//右前电机停止
	Motor_RR_stop();			//右后电机停止
	
}


/**
  * @brief  通过控制电机来控制小车后退左转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Left_Back(unsigned char speed)
{
	Motor_RF_back(speed);		//右前电机反转
	Motor_RR_back(speed);		//右后电机反转
	Motor_LF_stop();			//左前电机停止
	Motor_LR_stop();			//左后电机停止
}


/**
  * @brief  通过控制电机来控制小车后退右转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Right_Back(unsigned char speed)
{
	Motor_LF_back(speed);		//左前电机反转
	Motor_LR_back(speed);		//左后电机反转
	Motor_RF_stop();			//右前电机停止
	Motor_RR_stop();			//右后电机停止
}


/**
  * @brief  通过控制电机来控制小车原地左转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Left_Stop(unsigned char speed)
{
	Motor_RF_go(speed);			//右前电机正转
	Motor_LF_back(speed);		//左前电机反转
	Motor_LR_back(speed);		//左后电机反转
	Motor_RR_go(speed);			//右后电机正转
}


/**
  * @brief  通过控制电机来控制小车原地右转
  * @param  speed 速度（0-20）
  * @retval 无
  */
void Car_Right_Stop(unsigned char speed)
{
	Motor_LF_go(speed);			//左前电机正转
	Motor_RF_back(speed);		//右前电机反转
	Motor_RR_back(speed);		//右后电机反转
	Motor_LR_go(speed);			//左后电机正转
}

