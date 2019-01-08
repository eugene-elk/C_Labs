#include <stdio.h>

// Course: Programming (C)
// Lab 1. Developing console application
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 13.09.2016
// Description: input and output integer and char

int main()
{
	int a;
	char ch;
	scanf("%d %c", &a, &ch);
	printf("%d\n%c", a, ch);
	scanf("%d %c", &a, &ch);
	return 0;
}
