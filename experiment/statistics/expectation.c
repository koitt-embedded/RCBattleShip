#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_res(int *money, int *arr)
{
}

float get_expectation(char **d, int *money)
{
	int i, idx, len;
	char *arr[3] = {0};

	for(i = 0; i < 3; i++)
	{
		idx = rand() % 4;
		len = strlen(d[idx]);
		arr[i] = (char *)malloc(sizeof(char *) * (len + 1));
		strcpy(arr[i], d[idx]);
	}

	for(i = 0; i < 3; i++)
		printf("arr[%d] = %s\n", i, arr[i]);

	//check_res(money, arr);

	return 1;
}

int main(void)
{
	char *data[4] = {"dollar", "cherry", "lemon", "etc"};
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
