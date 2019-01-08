#include <stdio.h>

// Course: Programming (C)
// Lab 5. Arrays
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 21.09.2016
// Description: Output array. Matrix multiplication.

int main()
{
	int a[7] = {90, 76, 54, 23, 56, 12, 48};
	for(int x = 0; x < 7; x++)
		printf("%d ", a[x]);
	printf("\n");
	int m1[2][2] = {{2, 5}, {2, 2}};
	int m2[2][2] = {{1, 2}, {0, 1}};
	int m3[2][2];
	for(int x = 0; x < 2; x++)
	{
		for(int y = 0; y < 2; y++)
		{
			m3[x][y] = 0;
			for(int z = 0; z < 2; z++)
				m3[x][y] = m3[x][y] + m1[x][z]*m2[z][y];
			printf("%d ", m3[x][y]);
		}
		printf("\n");
	}
}