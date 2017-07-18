#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "vector3d.h"

typedef struct quaternion
{
	float real_w;
	vec3d image_v;
} quat;

void quaternion_add(quat A, quat B, quat *R);
void quaternion_minus(quat A, quat B, quat *R);
void quaternion_mult(quat A, quat B, quat *R);
void print_quaternion(quat R);

#endif
