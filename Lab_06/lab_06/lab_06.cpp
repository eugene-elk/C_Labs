#include <stdio.h>
#include <malloc.h>

// Course: Programming (C)
// Lab 6. Pointers and dynamic memory
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 19.10.2016
// Description: The array output with a pointer, dynamic array output.

int main()
{
	int a[4];
	int *p = &a[0];
	for(int x = 0; x < 4; x++)
	{
		scanf("%d", &a[x]);
	}
	for(int x = 0; x < 4; x++)
	{
		printf("%d ", *(p + x));
	}
	printf("\n");
	p = (int*)malloc(4*sizeof(int));;
	for(int x = 0; x < 4; x++)
	{
		scanf("%d", &p[x]);
	}
	for(int x = 0; x < 4; x++)
	{
		printf("%d ", *(p + x));
	}
	printf("\n");
	free(p);
	return 0;
}