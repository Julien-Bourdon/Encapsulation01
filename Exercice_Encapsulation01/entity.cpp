#include <iostream>

#include "entity.h"

Entity::Entity(float _x, float _y) : Position(_x, _y) {

}


Vector2* Entity::GetPosition() {
	return &Position;
}

void Entity::SetPosition(float _x, float _y) {
	Position.SetX(_x);
	Position.SetY(_y);
}