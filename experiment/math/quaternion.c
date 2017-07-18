#include <stdio.h>

#include "quaternion.h"
#include "vector3d.h"

void quaternion_add(quat A, quat B, quat *R)
{
        R->real_w = A.real_w + B.real_w;
        vec3d_add(A.image_v, B.image_v, &R->image_v);
}

void quaternion_minus(quat A, quat B, quat *R) 
{
        R->real_w = A.real_w - B.real_w;
        vec3d_minus(A.image_v, B.image_v, &R->image_v);
}

void print_quaternion(quat R)
{
	printf("Real w = %.5f, ", R.real_w);
	print_vec3d(R.image_v);
}
