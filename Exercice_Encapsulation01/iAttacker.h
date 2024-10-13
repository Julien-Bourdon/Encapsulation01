#pragma once

#ifndef IATTACKER_H__
#define IATTACKER_H__

class IAttacker {
private:

protected:

public:

	//virtual float Attack(float* _ptrHP) = 0;

	//On souhaite avoir comme pointage l'entity que l'on attaque
	virtual float Attack(Alive* ptrTarget) = 0;
};


#endif