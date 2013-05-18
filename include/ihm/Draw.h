#ifndef ITD_DRAW_H_
#define ITD_DRAW_H_

#include "element/Monster.h"
#include "element/Tower.h"
/*#include "element/Shot.h"*/
#include "ihm/Node.h"

/************* Prototypes des fonctions *************/
//Dessine la carte
int drawMap (GLuint*);
//Dessin le menu
int drawMenu (GLuint*, GLuint*, GLuint*, int);
//Dessin des tours
int drawTower (GLuint*, LTower*, LMonster*, Monster*, int, int);
//Dessin des missiles
int drawShot (GLuint*, LShot*);
//Dessine les monstres
int drawMonster(GLuint*, LMonster*);
//Dessine la barre de pv des monstres
int drawPVMonster(LMonster*);

//Dessiner un disque
void drawDisque(float);
//Dessiner un clercle
void drawCercle(float);
//Dessiner un rectangle
void drawRectangle (int, int, int, int);
//Dessiner le contour d'un rectangle
void drawRectangleLine (int, int, int, int);
//Ecrire du texte
void writeString(int, int,  char*);

#endif