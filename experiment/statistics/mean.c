#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LEN		10

typedef struct mode_val
{
	float val;
	int freq;
} mv;

mv mode_val_arr[10] = {0};
float arr[LEN] = {0};

void init_arr(void)
{
	int i;

	for(i = 0; i < LEN; i++)
		arr[i] = rand() % 100 + 1;
}

void print_arr(void)
{
	int i;

	for(i = 0; i < LEN; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	printf("\n");
}

float get_mean(void)
{
	int i;
	float sum;

	for(i = 0; i < LEN; i++)
		sum += arr[i];

	return sum / LEN;
}

float get_median(void)
{
	int i;
	
	if(LEN % 2)
		return arr[LEN / 2];
	else
		return (arr[LEN / 2] + arr[LEN / 2 - 1]) / 2.0;
}

float get_mode(float *mode_arr)
{
	int i, cnt = 0;
	
	mode_val_arr[0].val = mode_arr[0];
	mode_val_arr[0].freq = 1;

	printf("mv[0].val = %f, freq = %d\n", mode_val_arr[0].val, mode_val_arr[i].freq);

	for(i = 1; i < LEN; i++)
	{
		if(mode_val_arr[cnt].val == mode_arr[i])
		{
			printf("True\n");
			mode_val_arr[cnt].freq++;
		}
		else
		{
			printf("False\n");
			mode_val_arr[cnt++].val = mode_arr[i];
			mode_val_arr[cnt].freq = 1;
		}

		printf("mv[%d].val = %f, freq = %d\n", i, mode_val_arr[i].val, mode_val_arr[i].freq);
		printf("mode_arr[%d] = %f\n", i, mode_arr[i]);
	}

	printf("cnt = %d\n", cnt);

	return;
}

int main(void)
{
	float mode_arr[10] = {1, 1, 1, 3, 3, 3, 3, 7, 7, 7};
	srand(time(NULL));

	init_arr();

	print_arr();

	printf("평균값 : %f\n", get_mean());
	printf("중앙값 : %f\n", get_median());
	printf("최빈값 : %f\n", get_mode(mode_arr));

	return 0;
}
