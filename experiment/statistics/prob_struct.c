#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct prob
{
	float p;
	float q;
} pg;

float total;

void init_pg(pg *e1, pg *e2)
{
	float tmp1, tmp2;
redo:
	tmp1 = rand() % 100 + 1;
	tmp2 = rand() % 100 + 1;
	if(tmp1 + tmp2 > total)
		goto redo;

	e1->p = tmp1 / total;
	e1->q = 1 - e1->p;

	e2->p = tmp2 / total;
	e2->q = 1 - e2->p;
}

void print_pg(pg g)
{
	printf("p = %.2f\n", g.p * 100.0);
	printf("q = %.2f\n", 100.0 - g.p * 100.0);
}

pg mutual_exclusive_event(pg e1, pg e2)
{
	pg res;

	res.p = e1.p + e2.p;
	res.q = 1.0 - res.p;

	return res;
}

float init_total(void)
{
	return rand() % 100 + 1;
}

int main(void)
{
	pg res, red, black;

	srand(time(NULL));

	total = init_total();
	init_pg(&red, &black);

	print_pg(red);
	print_pg(black);

	res = mutual_exclusive_event(red, black);
	print_pg(res);

	return 0;
}
