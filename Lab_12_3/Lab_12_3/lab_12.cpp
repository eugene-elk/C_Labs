#include<stdio.h>

// Course: Programming (C)
// Lab 12. Input and output operations
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 29.11.2016
// Description: use the command line, read from a file


int main(int argc, char** argv)
{
	if (argc == 1)
		scanf("%s", argv[1]);
	FILE *in = fopen(argv[1], "r");
	char c[100];
	int i = 0;
	if(in != NULL)
	{
		while(fgets(c, 100, in) != NULL)
		{
			i++;
			if((i % 2) == 0)
				printf("%s", c);
		}
		fclose(in);
		printf("\n");
	}
	else
		printf("\nerror\n");
	return 0;
}
