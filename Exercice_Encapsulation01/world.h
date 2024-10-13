#pragma once

#ifndef WORLD_H__
#define WORLD_H__

#include <iostream>
#include <vector>
#include "entity.h";


class World {
protected:
	std::vector<Entity*> ptr_Entitys;
	//stock bien des pointeurs de Entity dans un vecteur

public:
	void Init();

	//Fonction pour vérifier si la variable ptr_Entitys ajoute bien toutes les entitys
	//void Display_Ptr();

	bool Step();
	World();
};



#endif