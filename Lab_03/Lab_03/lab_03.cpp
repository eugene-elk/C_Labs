#include <stdio.h>

// Course: Programming (C)
// Lab 3. Representation of numbers in different number systems and bit operations.
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 19.09.2016
// Description: Input and output numbers in different number systems, bit operations: negation, shift, or.

int main()
{
	int a, b;
	scanf("%o %o", &a, &b);
	printf("%d\n", a);
	printf("%o\n", a);
	printf("%o\n", a >> 3);
	printf("%o\n", a);
	printf("%o\n", ~a);
	printf("%o\n", a|b);
	return 0;
}