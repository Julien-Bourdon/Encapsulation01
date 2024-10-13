#pragma once

#ifndef BREAKABLEOBJECT_H__
#define BREAKABLEOBJECT_H__

#include "entity.h"
#include "aLive.h"

class BreakableObject : public Entity, public Alive {
private:
protected:
public:
	void TakeDamage() override;

	BreakableObject(float _x, float _y, float _actualHp, float _maxHp);
};


#endif
