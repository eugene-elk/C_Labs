#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <locale.h>

struct Point {
	float x, y;
};

struct Pentagon {
	struct Point Center;
	struct Point point1;
	float R;
};

float perimeter(Pentagon*);

struct Pentagon* create(float, float, float, float);

#endif HEADER_H