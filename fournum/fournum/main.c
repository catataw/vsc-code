#include<stdio.h>
#include"fournum.h"

// main 
int main()
{
	double px, py, pz;
	double ax, ay, az, th;
	quaternion ppp;

	while (1) {
		printf("Point Position (x, y, z) \n");
		scanf("%lf %lf %lf", &px, &py, &pz);
		ppp = putxyz_to_quaternion(px, py, pz);

		printf(" ‰»ÎΩ«∂»£∫\n");
		scanf("%lf", &th);
		if (th == 0.0) break;

		printf("Rotation Axis Direction ? (x, y, z) \n");
		scanf("%lf %lf %lf", &ax, &ay, &az);

		make_rotate(&ppp, th, ax, ay, az);

		printf_quaternion(&ppp);
	}
	return 0;
}