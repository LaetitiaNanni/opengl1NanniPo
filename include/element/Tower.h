#ifndef LDR_TOWER___
#define LDR_TOWER___

typedef struct struct_tower {

	//Type de la tour : R (rocket) L (laser), M (mitraillette) et H (hybride)
	char type;

	//puissance de tir
	float power;

	//cadence 
	float rate;

	//porté de la tour
	float range;

	//cout de la tour
	int cost;

}Tower;

//liste de tour
typedef struct struct_ltower {

	//Taille de la liste
	size_t length;

	//Pointeur
	Tower *p_head; //pointeur vers le premier element
	Tower *p_tail; //pointeur vers le dernier element
}LTower;

#endif
