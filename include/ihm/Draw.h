#ifndef ITD_DRAW_H_
#define ITD_DRAW_H_

#include "element/Monster.h"
#include "element/Tower.h"
#include "element/Shot.h"
#include "ihm/Node.h"

/************* Prototypes des fonctions *************/
//Dessin menu Map
int drawMenuMap (GLuint*);
//Dessin du menu principal
int drawMenuPrincipale (GLuint*, GLuint*);
//Dessine la carte
int drawMap (GLuint*);
//Dessin de l'aide
int drawHelp (GLuint*, GLuint*, GLuint*, int);
//Dessin le menu du haut
int drawMenuUp (GLuint*, GLuint*, int);
//Dessin du menu de gauche
int drawMenuLeft(GLuint*, GLuint*, Interface*);
//Dessiner l'interface (score, argent, vie, nb de monstre tués
int drawInterface (GLuint*, Interface*);
//Affiche propriete d'une tour
int drawProprieteTower (GLuint*, GLuint*, Tower*, Interface*);
//Affiche les propriétés du monstre
int drawProprieteMonster (GLuint*, Monster*);

//Dessin des tours
int drawTower (GLuint*, LTower*, LMonster*, Tower*, int, int);
//Dessin des missiles
int drawShot (GLuint*, LShot*);
//Dessine les monstres
int drawMonster(GLuint*, LMonster*, int);
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
