#include <time.h>
#include <stdio.h>
#include <stdlib.h>

float dollar = 0.1;
float cherry = 0.2;
float lemon = 0.2;
float etc = 0.5;

void check_res(int *money, int *arr)
{
	int twenty[3] = {0.1, 0.1, 0.1};
	int fifteen[3][3] = {{0.1, 0.1, 0.2}, {0.1, 0.2, 0.1}, {0.2, 0.1, 0.1}};
	int ten[3] = {0.2, 0.2, 0.2};
	int five[3] = {

	if(memcmp(
}

float get_expectation(float *d, int *money)
{
	int i;
	int arr[3] = {0};
	float tmp = 1;

	for(i = 0; i < 3; i++)
	{
		arr[i] = rand() % 4;
		tmp *= d[arr[i]];
	}

	check_res(money, arr);

	return tmp;
}

int main(void)
{
	float data[4] = {dollar, cherry, lemon, etc};
	float prob;
	int i, money = 0;

	srand(time(NULL));	

	for(i = 0; i < 10; i++)
	{
		prob = get_expectation(data, &money);
		printf("prob = %.2f%c\n", prob * 100.0, 0x25);
	}

	return 0;
}
