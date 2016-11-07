
#include "fournum.h"

quaternion quaternion_multiply(quaternion left, quaternion right)
{
	quaternion ans;
	double d1, d2, d3, d4;

	d1 = left.t * right.t;
	d2 = -left.x * right.x;
	d3 = -left.y * right.y;
	d4 = -left.z * right.z;
	ans.t = d1 + d2 + d3 + d4;

	d1 = left.t * right.x;
	d2 = right.t * left.x;
	d3 = left.y * right.z;
	d4 = -left.z * right.y;
	ans.x = d1 + d2 + d3 + d4;

	d1 = left.t * right.y;
	d2 = right.t * left.y;
	d3 = left.z * right.x;
	d4 = -left.x * right.z;
	ans.y = d1 + d2 + d3 + d4;

	d1 = left.t * right.z;
	d2 = right.t * left.z;
	d3 = left.x * right.y;
	d4 = -left.y * right.x;
	ans.z = d1 + d2 + d3 + d4;

	return ans;
}

//将旋转角度和旋转轴 转换成四元素
quaternion make_rotational_quaternion(double radian, double AxisX, double AxisY, double AxisZ)
{
	quaternion ans;
	double norm;
	double ccc, sss;

	ans.t = ans.x = ans.y = ans.z = 0.0;

	norm = AxisX *  AxisX + AxisY *  AxisY + AxisZ *  AxisZ;
	if (norm <= 0.0) return ans;

	norm = 1.0 / sqrt(norm);
	AxisX *= norm;
	AxisY *= norm;
	AxisZ *= norm;

	ccc = cos(0.5 * radian);
	sss = sin(0.5 * radian);

	ans.t = ccc;
	ans.x = sss * AxisX;
	ans.y = sss * AxisY;
	ans.z = sss * AxisZ;

	return ans;
}

// 将要旋转的点 XYZ 转换成四元素 
quaternion putxyz_to_quaternion(double PosX, double PosY, double PosZ)
{
	quaternion ans;

	ans.t = 0.0;
	ans.x = PosX;
	ans.y = PosY;
	ans.z = PosZ;

	return ans;
}

void printf_quaternion(quaternion *fournum)
{
	printf("坐标：(%0.2lf,%0.2lf,%0.2lf)\n", fournum->x, fournum->y, fournum->z);
}
void make_rotate(quaternion *fournum,double radian, double AxisX, double AxisY, double AxisZ)
{
	quaternion qqq,rrr;
	radian *= pai / 180.0; /// Degree -> radian;
	qqq = make_rotational_quaternion(radian, AxisX, AxisY, AxisZ);
	rrr = make_rotational_quaternion(-radian, AxisX, AxisY, AxisZ);

	*fournum = quaternion_multiply(rrr, *fournum);
	*fournum = quaternion_multiply(*fournum, qqq);
}