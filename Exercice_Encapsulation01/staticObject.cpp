#include <iostream>
#include "staticObject.h"

StaticObject::StaticObject(float _x, float _y) : Entity(_x, _y) {
	std::cout << "StaticObject just created at x = "
		<< _x << " and y = " << _y << std::endl;
}


