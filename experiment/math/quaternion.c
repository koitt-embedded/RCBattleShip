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

void quaternion_mult(quat A, quat B, quat *R)
{
	/*
	R->real_w    = B.real_w    * A.real_w    - B.image_v.x * A.image_v.x
		     - B.image_v.y * A.image_v.y - B.image_v.z * A.image_v.z;
	R->image_v.x = B.real_w    * A.image_v.x + B.image_v.x * A.real_w
		     + B.image_v.y * A.image_v.z - B.image_v.z * A.image_v.y;
	R->image_v.y = B.real_w    * A.image_v.y - B.image_v.x * A.image_v.z
		     + B.image_v.y * A.real_w    + B.image_v.z * A.image_v.x;
	R->image_v.z = B.real_w    * A.image_v.z + B.image_v.x * A.image_v.y
		     - B.image_v.y * A.image_v.x + B.image_v.z * A.real_w;
	*/

	vec3d tmp_cross = {0};
	vec3d tmp_scalar1 = {0};
	vec3d tmp_scalar2 = {0};

	R->real_w = A.real_w * B.real_w - vec3d_inner(A.image_v, B.image_v);

	vec3d_cross(A.image_v, B.image_v, &tmp_cross);
	vec3d_scalar(A.real_w, B.image_v, &tmp_scalar1);
	vec3d_scalar(B.real_w, A.image_v, &tmp_scalar2);

	R->image_v.x = tmp_cross.x + tmp_scalar1.x + tmp_scalar2.x;
	R->image_v.y = tmp_cross.y + tmp_scalar1.y + tmp_scalar2.y;
	R->image_v.z = tmp_cross.z + tmp_scalar1.z + tmp_scalar2.z;
}

void print_quaternion(quat R)
{
	printf("Real w = %.5f, ", R.real_w);
	print_vec3d(R.image_v);
}
