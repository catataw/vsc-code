#pragma once
#include <math.h> 
#include<stdio.h>
#define pai 3.1415926535897932384626433832795
//��Ԫ���Ľṹ��

typedef struct
{
	double t; // real
	double x; // x
	double y; // y
	double z; // z
} quaternion;

/*
 * \brief		����PosX,PosY,PosZ��ת����һ����Ԫ��
 * \param PosX	��Ӧ��x����
 * \param PosY	��Ӧ��y����
 * \param PosZ	��Ӧ��z����
 * \return		����һ����Ԫ������
 */
quaternion putxyz_to_quaternion(double PosX, double PosY, double PosZ);
/*
 * \brief			����һ����Ԫ���������ƣ�AxisX,AxisY,AxisZ����תradian������귵��
 * \param fournum	��Ҫ��ת����Ԫ��
 * \param radian	��ת�Ƕ�
 * \param AxisX,AxisY,AxisZ:�ƴ�������ת
 * \return			no return
 */
void make_rotate(quaternion *fournum, double radian, double AxisX, double AxisY, double AxisZ);

/*
 * \brief			��ӡ��Ԫ��
 * \param fournum	����ӡ�Ķ���
 * \return			no return
 */
void printf_quaternion(quaternion *fournum);
/*
 * \brief			��Ԫ���ĳ˷�
 * \param left		��Ԫ
 * \param right		��Ԫ
 * \return			һ����Ԫ��(left*right)
 */
quaternion quaternion_multiply(quaternion left, quaternion right);

/*
 * \brief			��p��AxisX,AxisY,AxisZ����ת�Ƕ�radian,��P��p�ĵ�λ����������������һ����Ԫ��{cos(radian/2)+sin(radian/2)*(Px+Py+Pz))
 * \param radian		��Ҫ��ת�ĽǶ�
 * \return			һ����Ԫ������
 */
quaternion make_rotational_quaternion(double radian, double AxisX, double AxisY, double AxisZ);


