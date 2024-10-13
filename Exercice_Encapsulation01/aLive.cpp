#include <iostream>

#include "alive.h"

Alive::Alive(float _hp, float _maxHp) : ActualHP(_hp), MaxHP(_maxHp) {

}

float Alive::GetMaxHP()
{
	return MaxHP;
}

//Du coup, en passant directement par le pointeurGetActuelHP, plus besoin de celle ci ?
float Alive::GetActualHP()
{
	return ActualHP;
}

void Alive::TakeDamage()
{
	ActualHP -= 10;
}

float* Alive::Ptr_GetActualHP()
{
	return &ActualHP;
}