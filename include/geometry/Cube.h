#ifndef LDR_CUBE___
#define LDR_CUBE___

#include "geometry/Point3D.h"
#include "geometry/Color3f.h"
#include "geometry/Shape.h"

typedef struct struct_cube {
	ShapeType type;
	Point3D point1;
	Point3D point2;
	Color3f color;
}Cube;

Cube CubeInit(Point3D, Point3D, Color3f);

#endif
