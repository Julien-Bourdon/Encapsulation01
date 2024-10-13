#pragma once

#ifndef VECTOR2_H__
#define VECTOR2_H__

class Vector2 {
private:
	float x;
	float y;
public:
	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	Vector2();
	Vector2(float, float);
};


#endif