#ifndef LDR_SPHERE___
#define LDR_SPHERE___

#include "geometry/Point3D.h"
#include "geometry/Color3f.h"
#include "geometry/Shape.h"

typedef struct struct_sphere {
	ShapeType type;
	Point3D center;
	float radius;
	Color3f color;
}Sphere;

Sphere SphereInit(Point3D, float, Color3f);

#endif
