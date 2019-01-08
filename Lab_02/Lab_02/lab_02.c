#include <stdio.h>
#include <math.h>

// Course: Programming (C)
// Lab 2. Calculating of value of the function at the point
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 13.09.2016
// Description: calculates values of 2 functions

int main()
{
	float a;
	float z1, z2;
	scanf("%f", &a);
	z1 = cos(a) + cos(2*a) + cos(6*a) + cos(7*a);
	z2 = 4*cos(a/2)*cos(5/2*a)*cos(4*a);
	printf("%f\n%f", z1, z2);
	return 0;
}
