#include <iostream>
#include "breakableObject.h"


BreakableObject::BreakableObject(float _x, float _y, float _actualHp, float _maxHp)
	: Entity(_x, _y), Alive(_actualHp, _maxHp)
{
	std::cout << "BreakableObject just created at x = "
		<< _x << " and y = " << _y << " with " << _actualHp << " / " << _maxHp << " HP." << std::endl;
}

void BreakableObject::TakeDamage()
{
	float _damage = 10;
	ActualHP -= _damage;
	std::cout << " --> BreakableObject takes " << _damage << "damage !";

	if (ActualHP <= 0)
	{
		std::cout << " --> BreakableObject is destroyed !!!" << std::endl;
	}
	else {
		std::cout << " BreakableObject still alive with " << ActualHP << " HP." << std::endl << std::endl;
	}
};


