#pragma once

#ifndef ENTITY_H__
#define ENTITY_H__

#include "vector2.h"

class Entity {
private:

protected:
	Vector2 Position;
public:
	virtual Vector2* GetPosition();
	virtual void SetPosition(float x, float y);

	Entity(float, float);  

};
#endif
