#pragma once
#ifndef MOB_H__
#define MOB_H__

#include "entity.h"
#include "alive.h"
#include "aMovable.h"
#include "iAttacker.h"

class Mob : public Entity, public Alive, public AMovable, public IAttacker {
private:

protected:

public:

	//float Attack(float* _ptrHp) override;
	//Quand on utilise Attack, on veut cibler directement les pdvs et éviter des copies de HP cible
	float Attack(Alive* _ptrTarget) override;
	void TakeDamage() override;

	virtual void Deplacement(float _positionX, float _positionY) override;
	float GetVitesse() override;
	void SetPosition(float _x, float _y);

	Mob(float _x, float _y, float _actualHp, float _maxHp, float _vitesse, Vector2 _direction);
};



#endif