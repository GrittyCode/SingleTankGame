#pragma once
#include <cmath>

typedef struct MyVector2
{
	float x;
	float y;
		
	MyVector2 operator - (MyVector2 rbs) const { return MyVector2({ x - rbs.x, y - rbs.y }); };
	MyVector2 operator + (MyVector2 rbs) const { return MyVector2({ x + rbs.x, y + rbs.y }); };
	MyVector2 operator * (float mul) const { return MyVector2({ x * mul, y * mul }); };
	MyVector2 operator / (float div) const { return MyVector2({ x / div, y / div }); };

	const void operator -= (MyVector2 rbs)  { x -= rbs.x; y -= rbs.y; };
	void operator += (MyVector2 rbs)  { x += rbs.x; y += rbs.y; };
	void operator *= (float mul)  { x *= mul; y *= mul; };
	void operator /= (float div) { x /= div; y /= div; };

	//distance, normalize,내적
	float distance() { return sqrt((pow(x, 2) + pow(y, 2))); }
	void normalize() { x /= distance(); y /= distance(); }
	//arccos을 하면은 상대 벡터와 나의 벡터의 세타 각도의 라디안 값이 나온다.
	float dotProduct(MyVector2 rbs) { return (x * rbs.x) + (y * rbs.y); };

}Vecotr2;