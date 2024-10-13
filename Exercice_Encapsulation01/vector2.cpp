#include "vector2.h"

//Initialisation de la class Vector2
Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {

}

Vector2::Vector2() : x(0.0f), y(0.0f) {}

float Vector2::GetX() {
	return x;
}
float Vector2::GetY() {
	return y;
}

void Vector2::SetX(float _x) {
	x = _x;
}

void Vector2::SetY(float _y) {
	y = _y;
}

