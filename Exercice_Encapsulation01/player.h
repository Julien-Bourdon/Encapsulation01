#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

#include "entity.h"
#include "aLive.h"
#include "aMovable.h"
#include "iAttacker.h"

class Player : public Entity, public Alive, public AMovable, public IAttacker {
private:
protected:
public:
	virtual void Deplacement(float _positionX, float _positionY) override;

	//float Attack(float *_ptrHp);
	float Attack(Alive* target) override;
	void TakeDamage() override;

	float GetVitesse() override;
	void SetPosition(float _x, float _y);

	Player(float _x, float _y, float _actualHp, float _maxHp, float _vitesse, Vector2 _direction);
};




#endif