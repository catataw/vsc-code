#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include "distortion.h"
#include "assert.h"


float p = 1.0;//����
double k1 = 0.003917f;
double k2 = 0.008985f;
double k3 = 1.34443e-4;
double k4 = -2.92180e-7;
double k5 = -3.0252e-7;
double k6 = 1.04549e-8;
double k7 = -9.78497e-11;
float centerX = 0.5;
float centerY = 0.5;
float height = 72;//������Ļ�ĸ߶�
float width = 64.8f;//������Ļ�Ŀ��


float* distortion(int eye, float u, float v) {
	//u -= 0.4;//ƽ��
	float u1, v1, U;
	float r,x;
	float *a = (float *)malloc(sizeof(float)* 2);
	if (a == NULL)return NULL;
	memset(a, 0, sizeof(float)* 2);

	//��[0,1]����Ļ��Χӳ����������������
	u1 = abs(u - centerX)*height;
	v1 = abs(v - centerX)*width;
	r= sqrt(v1*v1 + u1*u1);

	//Ȼ��Ե�������������
	//U��ʾ���ǣ������������У�(u,v)�㵽(0.5,0.5)���ĵ�ľ���r����Ӧ�Ļ����ʡ�
	//r��Ӧ���ݵ�Y Angle  U��Ӧ�����е�Distortion
	U = k7*pow(r, 7) + k6*pow(r, 6) + k5*pow(r, 5) + k4*pow(r, 4) + k3*pow(r, 3) + k2*pow(r, 2) + k1*r;
	
	U = U / 100;//��С100��

	//r*x*(1+U) = r ��� x=1/(1+U)
	x = 1 / (1 + U);
	//Ҫ���̱���Ӧ�ó���һ��С��1��ϵ�������Ǵ˴��෴����Ӧ���������㻭�����Ŵ������һ�㣬�����һ����Ȼ����С��
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