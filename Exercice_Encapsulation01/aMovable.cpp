#include <iostream>
#include "aMovable.h"

AMovable::AMovable(float _v, Vector2 _d) : Vitesse(_v), Direction(_d)
{

}

void AMovable::SetDirection(Vector2 _d) {
	Direction = _d;
}

void AMovable::SetVitesse(float _v) {
	Vitesse = _v;
}
