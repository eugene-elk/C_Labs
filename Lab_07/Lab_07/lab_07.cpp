#include <stdio.h>

// Course: Programming (C)
// Lab 7. Types of user-defined data
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 21.09.2016
// Description: the use of an enumerated data type, structure, bit field and union.

enum Cond {���� = 1, �������� = 2, ��������� = 3, ������� = 4};

struct foursquare
{
	int x, y;
	int side_length;
	int square(){
		return side_length*side_length;
	}
};

struct printer_properties
{
	int ready: 1;
	int toner: 1;
	int damaged: 1;
	int paper: 1;
};

union printer
{
	printer_properties PP;
	char c;
};

int main()
{
	printf("%d \n", �������);
	foursquare A;
	A.side_length = 10;
	printf("%d \n", A.square());
	printer p1;
	scanf("%x", &p1.c);
	printf("%d %d %d %d\n", p1.PP.ready, p1.PP.toner, p1.PP.damaged, p1.PP.paper);
	return 0;
}