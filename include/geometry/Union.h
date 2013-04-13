#ifndef LDR_UNION_3D___
#define LDR_UNION_3D___

#include "geometry/Point3D.h"
#include "geometry/Color3f.h"
#include "geometry/Vector3D.h"
#include "geometry/Ray3D.h"
#include "geometry/Sphere.h"
#include "geometry/Shape.h"
#include "geometry/Cube.h"

typedef union {
	ShapeType type;
	Sphere sphere;
	Cube cube;
}Shape;

#endif
