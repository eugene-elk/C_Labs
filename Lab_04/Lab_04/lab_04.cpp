#include <stdio.h>

// Course: Programming (C)
// Lab 4. Logical operations
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 28.09.2016
// Description: Ñhecking number hits in range. Checking the value of the bit in number.

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf(((a >= 23) && (a <= 32))? "yes\n":"no\n");
	printf("%d\n", (b >> 6)%2);
}