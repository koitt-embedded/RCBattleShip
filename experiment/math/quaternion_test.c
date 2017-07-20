#include <stdio.h>

#include "quaternion.h"
#include "vector3d.h"

int main(void)
{
	quat A = {0.1, {1.0, 3.0, 2.0}};
	quat B = {0.3, {2.0, 3.0, 6.0}};
	quat C = {1.0, {-1.0, 2.0, -1.0}};
	quat D = {2.0, {-1.0, -2.0, 3.0}};
	quat R = {0};

	vec3d v = {1.0, 1.0, 1.0};
	vec3d r = {0};

	quaternion_add(A, B, &R);
	print_quaternion(R);

	quaternion_minus(A, B, &R);
	print_quaternion(R);

/*
	quaternion_mult(A, B, &R);
	print_quaternion(R);
*/

	quaternion_mult(C, D, &R);
	print_quaternion(R);

	printf("quaternion norm = %.5f\n", quaternion_norm(A));

	quaternion_conjugate(A, &R);
	print_quaternion(R);

	quaternion_reverse(A, &R);
	print_quaternion(R);

	quaternion_mult(A, R, &R);
	print_quaternion(R);

	quaternion_rotation(A, v, &r);
	print_vec3d(r);

	return 0;
}
