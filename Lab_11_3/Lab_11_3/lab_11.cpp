#include "header.h"

// Course: Programming (C)
// Lab 11. Using the header files
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 29.11.2016
// Description: creating a structure for the pentagon, pentagon perimeter calculation


int main() {
	setlocale(LC_ALL, "Rus");
	float x1, y1, x2, y2;
	printf("Введите координаты центра пятиугольника\n");
	scanf("%f %f", &x1, &y1);
	printf("Введите координаты одной из вершин пятиугольника\n");
	scanf("%f %f", &x2, &y2);
	Pentagon Pnt = *create(x1, y1, x2, y2);
	printf("Периметр пятиугольника:\n%f\n", perimeter(&Pnt));
	return 0;
}
