#include <stdio.h>

#include "quaternion.h"
#include "vector3d.h"

int main(void)
{
	quat A = {0.1, {1.0, 3.0, 2.0}};
	quat B = {0.3, {2.0, 3.0, 6.0}};
	quat R = {0};

	quaternion_add(A, B, &R);
	print_quaternion(R);

	quaternion_minus(A, B, &R);
	print_quaternion(R);

	quaternion_mult(A, B, &R);
	print_quaternion(R);

	return 0;
}
