#include "header.h"

float perimeter(Pentagon* Pnt) {
	return 5*(Pnt->R)*sqrt((5-sqrt(5.0))/2);
}

Pentagon* create(float x_c, float y_c, float x_p1, float y_p1) {
	Pentagon Pnt;
	Pnt.Center.x = x_c;
	Pnt.Center.y = y_c;
	Pnt.point1.x = x_p1;
	Pnt.point1.y = y_p1;
	Pnt.R = sqrt((x_c - x_p1)*(x_c - x_p1) + (y_c - y_p1)*(y_c - y_p1));
	return &Pnt;
}