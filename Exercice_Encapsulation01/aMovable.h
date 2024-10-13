#pragma once

#ifndef AMVOABLE_H__
#define AMOVABLE_H__

#include <iostream>
#include "vector2.h"

class AMovable {
private:

protected:
	float Vitesse;
	Vector2 Direction;

public:
	virtual void SetVitesse(float Vitesse);
	virtual void SetDirection(Vector2 Direction);
	virtual void Deplacement(float _positionX, float _positionY)=0;	
	//Fait devenir la class en class abstraite avec " =0", la fonction deviens <obligatoire> pour ces enfants
	//On veut directemnt gérer et viser les position X et Y sans faire de copie ?

	virtual float GetVitesse() = 0;

	AMovable(float, Vector2);
};



#endif