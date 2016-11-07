#pragma once
#include <math.h> 
#include<stdio.h>
#define pai 3.1415926535897932384626433832795
//四元数的结构体

typedef struct
{
	double t; // real
	double x; // x
	double y; // y
	double z; // z
} quaternion;

/*
 * \brief		将（PosX,PosY,PosZ）转化成一个四元数
 * \param PosX	对应的x坐标
 * \param PosY	对应的y坐标
 * \param PosZ	对应的z坐标
 * \return		返回一个四元数对象
 */
quaternion putxyz_to_quaternion(double PosX, double PosY, double PosZ);
/*
 * \brief			输入一个四元数，将其绕（AxisX,AxisY,AxisZ）旋转radian后的坐标返回
 * \param fournum	需要旋转的四元数
 * \param radian	旋转角度
 * \param AxisX,AxisY,AxisZ:绕此向量旋转
 * \return			no return
 */
void make_rotate(quaternion *fournum, double radian, double AxisX, double AxisY, double AxisZ);

/*
 * \brief			打印四元素
 * \param fournum	被打印的对象
 * \return			no return
 */
void printf_quaternion(quaternion *fournum);
/*
 * \brief			四元数的乘法
 * \param left		左元
 * \param right		右元
 * \return			一个四元数(left*right)
 */
quaternion quaternion_multiply(quaternion left, quaternion right);

/*
 * \brief			绕p（AxisX,AxisY,AxisZ）旋转角度radian,设P是p的单位向量。构造这样的一个四元数{cos(radian/2)+sin(radian/2)*(Px+Py+Pz))
 * \param radian		需要旋转的角度
 * \return			一个四元数对象
 */
quaternion make_rotational_quaternion(double radian, double AxisX, double AxisY, double AxisZ);


