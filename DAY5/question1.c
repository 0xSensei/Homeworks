#include <stdio.h>
#define SIZE 10

void masin()
{

	int set1[SIZE] = { 0 };
	int set2[SIZE] = { 0 };

	puts("Please Enter 10 decimals");
	//Parsing First Set
	for (size_t i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &set1[i]);
	}
	puts("Please Enter 10 decimals");
	//Parsing Second Set
	for (size_t i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &set2[i]);
	}


	int set3[20] = { 0 };
	int flag = 1;
	int counter = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{

			if (set1[i] == set2[j]) {
				flag = 0;
			}

		}
		if (flag)
		{
			printf("%d\n", set1[i]);
			set3[counter++] = set1[i];
		}
		flag = 1;
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{

			if (set2[i] == set1[j]) {
				flag = 0;
			}

		}
		if (flag)
		{
			printf("%d\n", set2[i]);
			set3[counter++] = set2[i];
		}
		flag = 1;
	}

	puts("Unique set is");
	for (size_t i = 0; i < counter; i++)
	{
		printf("%d ", set3[i]);
	}

}
