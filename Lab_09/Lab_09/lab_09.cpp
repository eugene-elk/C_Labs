#include <stdio.h>
#include <locale.h>

// Course: Programming (C)
// Lab 8. Loops and branching
// Student: Lositsky E.I. Group: M3105
// Teacher: Povyshev V.V.
// Created 16.11.2016
// Description: using loops and branching.

int main()
{
	setlocale(LC_ALL, "Rus");
	//2
	int cost_499, cost_minute, time, summ_cost;
	printf("¬ведите абонентскую плату:\n");
	scanf("%d", &cost_499);
	printf("¬ведите стоимость минуты сверх лимита\n");
	scanf("%d", &cost_minute);
	printf("¬ведите продолжительность разговоров:\n");
	scanf("%d", &time);
	if (time <= 499) summ_cost = cost_499;
	else{
		summ_cost = cost_499 + cost_minute*(time - 499);
	}
	printf("—тоимость мес€чного обслуживани€:\n");
	printf("%d\n", summ_cost);
	//4
	int x;
	printf("\n¬ведите границу вывода:\n");
	scanf("%d", &x);
	for(int i = 1; i <= x; i++)
	{
		int a = 0;
		for(int j = 1; j <= i; j++)
		{
			if(i%j == 0)
				a += j;
		}
		if (a - 1 == i)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}