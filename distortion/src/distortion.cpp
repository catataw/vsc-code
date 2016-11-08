#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include "distortion.h"
#include "assert.h"


float p = 1.0;//放缩
double k1 = 0.003917f;
double k2 = 0.008985f;
double k3 = 1.34443e-4;
double k4 = -2.92180e-7;
double k5 = -3.0252e-7;
double k6 = 1.04549e-8;
double k7 = -9.78497e-11;
float centerX = 0.5;
float centerY = 0.5;
float height = 72;//物理屏幕的高度
float width = 64.8f;//物理屏幕的宽度


float* distortion(int eye, float u, float v) {
	//u -= 0.4;//平移
	float u1, v1, U;
	float r,x;
	float *a = (float *)malloc(sizeof(float)* 2);
	if (a == NULL)return NULL;
	memset(a, 0, sizeof(float)* 2);

	//将[0,1]的屏幕范围映射成真正的物理距离
	u1 = abs(u - centerX)*height;
	v1 = abs(v - centerX)*width;
	r= sqrt(v1*v1 + u1*u1);

	//然后对的物理距离求畸变
	//U表示的是：在物理世界中，(u,v)点到(0.5,0.5)中心点的距离r所对应的畸变率。
	//r对应数据的Y Angle  U对应数据中的Distortion
	U = k7*pow(r, 7) + k6*pow(r, 6) + k5*pow(r, 5) + k4*pow(r, 4) + k3*pow(r, 3) + k2*pow(r, 2) + k1*r;
	
	U = U / 100;//缩小100倍

	//r*x*(1+U) = r 解得 x=1/(1+U)
	x = 1 / (1 + U);
	//要缩短本来应该乘以一个小于1的系数，但是此处相反。他应该是有两层画布，放大下面的一层，上面的一层自然就缩小了
	a[0] = (u - centerX) /x + centerX;
	a[1] = (v - centerY) /x + centerY;

	for (int i = 0; i < 2; i++)
	{
		a[i] = (a[i] - centerX)*p + centerX;
	}
	return a;
}
/*
float *A(int eye, float u, float v) {
	float *a = (float *)malloc(sizeof(float)* 2);
	{
		float r = sqrt((u - centerX)*(u - centerX) + (v - centerY)*(v - centerY));
		float s = (1 + 0.3*pow(r, 2));
		u = (u - centerX)*s + centerX;
		v = (v - centerY)*s + centerY;
	}
	a[0] = u;
	a[1] = v;
	return a;
}
*/