#pragma once

#ifndef ALIVE_H__
#define ALIVE_H__

class Alive {
protected:
	float MaxHP;
	float ActualHP;

public:
	virtual float GetMaxHP();
	virtual float GetActualHP();

	float* Ptr_GetActualHP();
	virtual void TakeDamage();

	Alive(float, float);
};



#endif