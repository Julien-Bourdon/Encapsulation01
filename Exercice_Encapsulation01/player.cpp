#include <iostream>
#include "player.h"

Player::Player(float _x, float _y, float _actualHp, float _maxHp, float _vitesse, Vector2 _direction)
	: Entity(_x, _y), Alive(_actualHp, _maxHp), AMovable(_vitesse, _direction)
{
	std::cout << "Player just created at x =" << _x << " and y = " << _y << " with " << _maxHp
		<< " HP with direction x = " << _direction.GetX() << " and direction y = " << _direction.GetY() << std::endl;
}

void Player::Deplacement(float _deltaX, float _deltaY)
{
	Vector2* currentPosition = GetPosition();
	float newX = currentPosition->GetX() + _deltaX;
	float newY = currentPosition->GetY() + _deltaY;

	std::cout << "Player moved to x = " << newX << " and y = " << newY << std::endl;

	SetPosition(newX, newY);
}

void Player::SetPosition(float _x, float _y)
{
	Position.SetX(_x);
	Position.SetY(_y);
}

float Player::Attack(Alive* ptr_Target)
{
	std::cout << " -->Player attack sa cible !<--" << std::endl;
	ptr_Target->TakeDamage();
	return ptr_Target->GetActualHP();
}

//Dans notre simulation, le joueur ne prend pour l'instant pas de dégat donc jamais utilisé
void Player::TakeDamage() {

	float _damage = 10;
	std::cout << "Player take " << _damage << " damage !" << std::endl;
	ActualHP -= _damage;
	if (ActualHP <= 0)
	{
		std::cout << "----> Player just died. GAME OVER" << std::endl;
	}
	else
	{
		std::cout << "----> Player still alive with " << ActualHP << " HP." << std::endl;
	}
}

float Player::GetVitesse() {
	return Vitesse;
}


