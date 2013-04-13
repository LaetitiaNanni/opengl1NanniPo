#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry/Color3f.h"

/* Color RGB : Couleur à partir des valeurs r, g, b */
Color3f ColorRGB(float r, float g, float b) {

	Color3f new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;

	return new_color;
}

/* Convertie un float en unsigned char */
unsigned char convert_f32_to_uc8 (float color) {

	return 255 * max(0, min(1, color));
}

float max(float limite, float color) {
	if(color < limite)
		return limite;
	else
		return color;

	/* (1/2)*abs(limite+color)+(1/2)*abs(limite-color) */
}

float min(float limite, float color) {
	if(color > limite)
		return limite;
	else
		return color;

	/* (1/2)*abs(limite+color)-(1/2)*abs(limite-color) */
}


/*AddColors : La fonction d’addition de couleur */
Color3f AddColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) + (C2.r);
	new_color.g = (C1.g) + (C2.g);
	new_color.b = (C1.b) + (C2.b);

	return new_color;
}

/*SubColors : La fonction de soustraction de couleur */
Color3f SubColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) - (C2.r);
	new_color.g = (C1.g) - (C2.g);
	new_color.b = (C1.b) - (C2.b);

	return new_color;
}

/* MultColors : La fonction de la multiplication de couleur */
Color3f MultColors(Color3f C1, Color3f C2){

	Color3f new_color;

	new_color.r = (C1.r) * (C2.r);
	new_color.g = (C1.g) * (C2.g);
	new_color.b = (C1.b) * (C2.b);

	return new_color;
}

/* DivColors : La fonction de la division couleur */
Color3f DivColors(Color3f C1, Color3f C2){

	Color3f new_color;

	if((C2.r) == 0 || (C2.g) == 0 || (C2.b) == 0) {
		printf("Erreur : impossible de diviser par 0");
		return C1;
	}

	new_color.r = (C1.r) / (C2.r);
	new_color.g = (C1.g) / (C2.g);
	new_color.b = (C1.b) / (C2.b);

	return new_color;
}
