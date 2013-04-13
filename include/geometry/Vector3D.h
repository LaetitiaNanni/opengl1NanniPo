#ifndef LDR_VECTOR_3D___
#define LDR_VECTOR_3D___

#include "geometry/Point3D.h"

typedef struct struct_vector {
	float x;
	float y;
	float z;
}Vector3D;

Vector3D VectorXYZ(float, float, float);
Vector3D Vector(Point3D, Point3D);
Vector3D AddVectors(Vector3D, Vector3D);
Vector3D SubVectors(Vector3D, Vector3D);
Vector3D MultVector(float, Vector3D);
Vector3D DivVector(float, Vector3D);
double DotProduct(Vector3D, Vector3D);
float Norm(Vector3D);
Vector3D Normalize(Vector3D);
Point3D PointPlusVector(Point3D, Vector3D);

#endif