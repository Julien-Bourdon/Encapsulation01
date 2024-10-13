#include <iostream>
#include "mob.h"

Mob::Mob(float _x, float _y, float _actualHp, float _maxHp, float _vitesse, Vector2 _direction)
	: Entity(_x, _y), Alive(_actualHp, _maxHp), AMovable(_vitesse, _direction)
{
	std::cout << "Mob just created at x= " << _x << " and y = " << _y << " with " << _maxHp 
		<< " HP, with direction.x = " << _direction.GetX() << " and direction.y = " << _direction.GetY() << std::endl;
}

float Mob::Attack(Alive* ptr_Target)
{
	std::cout << " -->Mob attack sa cible !<--" << std:: endl;
	ptr_Target->TakeDamage();
	return ptr_Target->GetActualHP(); // Retourne les HP restants
}

void Mob::TakeDamage()
{
	float _damage = 10;
	std::cout << " --> Mob take " << _damage << " damage !";
	ActualHP -= _damage;
	if (ActualHP <= 0)
	{
		std::cout << " ------> Mob die !!!" << std::endl;
	}
	else {
		std::cout << " ------> Mob still alive with " << ActualHP << " HP." << std::endl;
	}
}

void Mob::Deplacement(float _deltaX, float _deltaY){
	//Creer un nouveau Vector2 pour stocker la nouvelle position
	Vector2* currentPosition = GetPosition();
	float newX = currentPosition->GetX() + _deltaX;
	float newY = currentPosition->GetY() + _deltaY;

	std::cout << " Mob move to x = " << newX << " and y = " << newY << std::endl;

	// Utilisez SetPosition pour mettre à jour la position du mob
	SetPosition(newX, newY);
}

float Mob::GetVitesse() {
	return Vitesse;
}

void Mob::SetPosition(float _x, float _y)
{
	Position.SetX(_x);
	Position.SetY(_y);
}
