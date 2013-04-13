#ifndef LDR_RAY_3D___
#define LDR_RAY_3D___

#include "geometry/Point3D.h"
#include "geometry/Vector3D.h"

typedef struct struct_ray {
	Point3D origine;
	Vector3D direction;
}Ray3D;

#endif
