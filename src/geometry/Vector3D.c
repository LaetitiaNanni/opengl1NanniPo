#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Vector3D.h"
#include "geometry/Point3D.h"

/* Vector XYZ : Contruit un vecteur à partir de x, y, z */
Vector3D VectorXYZ(float x, float y, float z) {

	Vector3D new_vector;

	new_vector.x = x;
	new_vector.y = y;
	new_vector.z = z;

	return new_vector;
}

/* Vector : Contruit un vecteur à partir de deux points */
Vector3D Vector(Point3D A, Point3D B) {
	
	Vector3D new_vector;

	new_vector.x = (B.x) - (A.x);
	new_vector.y = (B.y) - (A.y);
	new_vector.z = (B.z) - (A.z);

	return new_vector;

}


/*AddVectors : La fonction d’addition de vecteurs */
Vector3D AddVectors(Vector3D V1, Vector3D V2){

	Vector3D new_vector;

	new_vector.x = (V1.x) + (V2.x);
	new_vector.y = (V1.y) + (V2.y);
	new_vector.z = (V1.z) + (V2.z);

	return new_vector;
}

/*SubVectors : La fonction de soustraction de vecteurs */
Vector3D SubVectors(Vector3D V1, Vector3D V2){

	Vector3D new_vector;

	new_vector.x = (V1.x) - (V2.x);
	new_vector.y = (V1.y) - (V2.y);
	new_vector.z = (V1.z) - (V2.z);

	return new_vector;
}

/* MultVector : La fonction de la multiplication d’un vecteur par un scalaire */
Vector3D MultVector(float lamba, Vector3D V){

	if(lamba == 1) 
		return V;

	Vector3D new_vector;

	new_vector.x = lamba * (V.x);
	new_vector.y = lamba * (V.y);
	new_vector.z = lamba * (V.z);

	return new_vector;

}

/* DivVector : La fonction de la division d’un vecteur par un scalaire */
Vector3D DivVector(float lambda, Vector3D V){

	Vector3D new_vector;

	if(lambda == 0) {
		printf("Erreur impossible de faire une division par 0");
		return new_vector;
	}
	else if(lambda == 1)
		return V;

	lambda = 1/lambda;

	new_vector.x = lambda * (V.x);
	new_vector.y = lambda * (V.y);
	new_vector.z = lambda * (V.z);

	return new_vector;

}


/* La fonction Norm calculant la norme d’un vecteur */
double DotProduct(Vector3D V1, Vector3D V2){

	Vector3D N1;
	Vector3D N2;

	N1 = Normalize(V1);
	N2 = Normalize(V2);

	return ((N1.x) * (N2.x)) + ((N1.y) * (N2.y)) + ((N1.z) * (N2.z));
}


/* La fonction Norm calculant la norme d’un vecteur */
float Norm(Vector3D V) {
	float norme;

	norme = ((V.x) * (V.x)) + ((V.y) * (V.y)) + ((V.z) * (V.z));
	norme = sqrt(norme);

	return norme;
}

/* Normalize : calcule le normalisé d’un vecteur */
Vector3D Normalize(Vector3D V){
	
	Vector3D new_vector;
	float norme = Norm(V);
	
	new_vector.x = (V.x) / norme;
	new_vector.y = (V.y) / norme;
	new_vector.z = (V.z) / norme;

	return new_vector;
}

/* PointPlusVector : Fonction d'addition d'un point et d'un vecteur = translation */
Point3D PointPlusVector(Point3D P, Vector3D V) {
	
	Point3D new_point;

	new_point.x = (P.x) + (V.x);
	new_point.y = (P.y) + (V.y);
	new_point.z = (P.z) + (V.z);

	return new_point;

}

