#include <stdio.h>

float total = 38;

#define	RED		1
#define BLACK		2
#define GREEN		3

#define ODD		0
#define EVEN		1

int data[38] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1,
		2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2,
		1, 2, 1, 2, 2, 1, 2, 1, 2, 1, 2, 1, 3, 3};

int count_data(int color)
{
	int i, cnt = 0;

	for(i = 0; i < total; i++)
		if(data[i] == color)
			cnt++;

	return cnt;
}

void count_eo(int *e, int *o)
{
	int i, cnt = 0;

	for(i = 0; i < total - 2; i++)
	{
		if(i % 2)
		{
			(*e)++;
		}
		else
		{
			(*o)++;
		}
	}
}

void count_cond_data(int color, int *e, int *o)
{
	int i, cnt = 0;

	for(i = 0; i < total - 2; i++)
	{
		if((i % 2) && (data[i] == color))
		{
			(*e)++;
		}
		else if(!(i % 2) && (data[i] == color))
		{
			(*o)++;
		}
	}
}

int main(void)
{
	int red, black, green, even = 0, odd = 0;
	int black_even = 0, black_odd = 0, red_even = 0, red_odd = 0;

	red = count_data(RED);
	black = count_data(BLACK);
	green = count_data(GREEN);

	printf("red = %d\n", red);
	printf("black = %d\n", black);
	printf("green = %d\n", green);

	count_eo(&even, &odd);
	printf("even = %d\n", even);
	printf("odd = %d\n", odd);

	count_cond_data(BLACK, &black_even, &black_odd);
	count_cond_data(RED, &red_even, &red_odd);
	printf("black_even = %d\n", black_even);
	printf("black_odd = %d\n", black_odd);
	printf("red_even = %d\n", red_even);
	printf("red_odd = %d\n", red_odd);

	return 0;
}
