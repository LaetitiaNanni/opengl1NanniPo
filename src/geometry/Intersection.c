#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Point3D.h"
#include "geometry/Color3f.h"
#include "geometry/Vector3D.h"
#include "geometry/Ray3D.h"
#include "geometry/Sphere.h"
#include "geometry/Cube.h"
#include "geometry/Union.h"
#include "geometry/Intersection.h"
#include "geometry/Shape.h"


int TestRaySphereIntersection(Ray3D ray, Sphere sphere,Intersection* intersection) {

	if(intersection == NULL) {
		printf("erreur\n");
		return 0;
	}

	/*float A = ((ray->direction->x)*(ray->direction->x)) + ((ray->direction->y)*(ray->direction->y)) + ((ray->direction->z)*(ray->direction->z))
	float B = 2*(((ray->direction->x)*((ray->origine->x) - (sphere->center->x))) + ((ray->direction->y)*((ray->origine->y) - (sphere->center->y))) + ((ray->direction->y)*((ray->origine->y) - (sphere->center->y))));*/

	double A = DotProduct((ray.direction), (ray.direction));
	Vector3D RoC = Vector((sphere.center), (ray.origine)); 
	double B = DotProduct(RoC, (ray.direction))*2.0;
	double C = DotProduct(RoC, RoC) - ((sphere.radius)*(sphere.radius));
	float Delta = (B*B) - 4*A*C;
	float t;

	if(Delta < 0)
		return 0;
	else {
		if(fabs(Delta) < 0.00000000001 && fabs(Delta) > -0.00000000001) {

			t = -B / (2*A);

			if(t < 0) 
				return 0;
		}

		else {
			float t1 = (-B + sqrt(Delta)) / (2*A);
			float t2 = (-B - sqrt(Delta)) / (2*A);

			float tmin = (t1<t2) ? t1 : t2;
			float tmax = (t1>t2) ? t1 : t2;

			if(tmax > 0)
				return 0;
			if(tmin > 0)
				t = tmin;
			else
				t = tmax;

			/*if(t1 < 0) 
				t = t2;
			else if(t2 < 0)
				t = t1;
			else if(t1 < t2 && t1 > 0)
				t = t1;
			else if(t2 < t1 && t2 > 0)
				t = t2;
			else
				return 0;*/
		}
		
		intersection->position = PointPlusVector((ray.origine), MultVector(t, (ray.direction)));
		intersection->color = sphere.color;
		return 1;
	}
}

int TestRayShapeIntersection(Ray3D ray, Shape shape,Intersection* intersection) {

	switch(shape.type) {

		case SPHERE_SHAPE:

			if(intersection == NULL) {
				printf("erreur\n");
				return 0;
			}

			double A = DotProduct((ray.direction), (ray.direction));
			Vector3D RoC = Vector((shape.sphere.center), (ray.origine)); 
			double B = DotProduct(RoC, (ray.direction))*2.0;
			double C = DotProduct(RoC, RoC) - ((shape.sphere.radius)*(shape.sphere.radius));
			float Delta = (B*B) - 4*A*C;
			float t;

			if(Delta < 0)
				return 0;
			else {
				if(fabs(Delta) < 0.00000000001 && fabs(Delta) > -0.00000000001) {

					t = -B / (2*A);

					if(t < 0) 
						return 0;
				}

				else {
					float t1 = (-B + sqrt(Delta)) / (2*A);
					float t2 = (-B - sqrt(Delta)) / (2*A);

					float tmin = (t1<t2) ? t1 : t2;
					float tmax = (t1>t2) ? t1 : t2;

					if(tmax > 0)
						return 0;
					if(tmin > 0)
						t = tmin;
					else
						t = tmax;

				}
		
				intersection->position = PointPlusVector((ray.origine), MultVector(t, (ray.direction)));
				intersection->color = shape.sphere.color;
				return 1;
			}
		break;

		case CUBE_SHAPE:

		break;

		default :
		break;
	}
}
