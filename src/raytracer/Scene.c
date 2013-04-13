#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Point3D.h"
#include "geometry/Ray3D.h"
#include "geometry/Color3f.h"
#include "geometry/Vector3D.h"
#include "geometry/Intersection.h"
#include "geometry/Union.h"
#include "geometry/Shape.h"
#include "raytracer/Scene.h"

void AddSceneShape(Scene* scene, Shape shape) {

	if(scene->nbObjects < SCENE_NB_OBJECT_MAX) {

		scene->objects[scene->nbObjects] = shape;
		scene->nbObjects ++;

	}
	else
		printf("Erreur : trop d'objets");
}


int ThrowRayOnScene(Ray3D ray, const Scene* scene, Intersection* intersection) {

	int intersectionFound = 0;
	unsigned int i;
	Intersection intersectionTmp;
	float distanceToCamera, distanceCameraTmp;

	for(i = 0; i < scene->nbObjects; i++) {

		if(TestRayShapeIntersection(ray, scene->objects[i], &intersectionTmp)) {

			distanceCameraTmp = Norm(Vector(PointXYZ(0, 0, 0), intersectionTmp.position));
			
			if(intersectionFound == 1) {

				if(distanceToCamera < distanceCameraTmp) {

					distanceToCamera = distanceCameraTmp;
					*intersection = intersectionTmp;
	
				}

			}
			else {

				intersectionFound = 1;
				distanceToCamera = distanceCameraTmp;

			}

		}

	}

	return intersectionFound;

}

/* surface carrée */
