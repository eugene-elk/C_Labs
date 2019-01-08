#include <stdio.h>
#include <string.h>

// Course: Programming (C)
// Lab 8. Strings
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 16.11.2016
// Description: makes operations with strings.

int main()
{
	char str1[100] = "", str2[100] = "";
	printf("Enter string 1:\n");
	scanf("%s", str1);
	printf("Enter string 2:\n");
	scanf("%s", str2);
	//задание 2
	int n;
	printf("Enter N:\n");
	scanf("%d", &n);
	strncat(str1, str2, n);
	printf("%s", str1);
	//задание 7
	printf("\nNumber of symbols in str1: %d\n", strlen(str1));
	//задание 9
	char *p1 = strrchr(str1, 'q');
	printf("Symbol 'q' is on %d position\n", p1-str1+1);
	//задание 11
	char str3[100] = "";
	printf("Enter string 3:\n");
	scanf("%s", str3);
	int res = 0;
	for (int i = 0; i<strlen(str3); i++)
		if(strchr(str1, str3[i])) 
			res += 1;
	printf("Number of similar symbols: %d\n", res);
	//задание 13
	char str4[100] = "";
	printf("Enter string 4:\n");
	scanf("%s", str4);
	char *lex = strtok(str4, str1);
	while (lex != NULL)
	{
		printf("%s\n", lex);
		lex = strtok(NULL, str1);
	}
	return 0;
}