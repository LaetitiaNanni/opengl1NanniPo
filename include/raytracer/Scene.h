#ifndef LDR_SCENE_3D___
#define LDR_SCENE_3D___

#define SCENE_NB_OBJECT_MAX 10

typedef struct struct_scene {

	Shape objects[SCENE_NB_OBJECT_MAX];
	unsigned int nbObjects;
	/* lumiere, camera*/
	
}Scene;

void AddSceneShape(Scene*, Shape);
int ThrowRayOnScene(Ray3D, const Scene*, Intersection*);

#endif
