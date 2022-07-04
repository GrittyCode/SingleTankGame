#pragma once
#include <cmath>

typedef struct MyVector2
{
	float x = 0.0f;
	float y = 0.0f;
	MyVector2() { x = 0.0f; y = 0.0f; }
	MyVector2(float p_x, float p_y) : x(p_x), y(p_y) {}

	MyVector2 operator - (MyVector2 rbs) const { return MyVector2({ x - rbs.x, y - rbs.y }); };
	MyVector2 operator + (MyVector2 rbs) const { return MyVector2({ x + rbs.x, y + rbs.y }); };
	MyVector2 operator * (float mul) const { return MyVector2({ x * mul, y * mul }); };
	MyVector2 operator / (float div) const { return MyVector2({ x / div, y / div }); };

	const void operator -= (MyVector2 rbs)  { x -= rbs.x; y -= rbs.y; };
	void operator += (MyVector2 rbs)  { x += rbs.x; y += rbs.y; };
	void operator *= (float mul)  { x *= mul; y *= mul; };
	void operator /= (float div) { x /= div; y /= div; };

	//distance, normalize,내적
	float distance() { return sqrtf((powf(x, 2) + powf(y, 2))); }
	void normalize() { x /= distance(); y /= distance(); }
	//arccos을 하면은 상대 벡터와 나의 벡터의 세타 각도의 라디안 값이 나온다.
	float dotProduct(MyVector2 rbs) { return (x * rbs.x) + (y * rbs.y); };

}Vector2;

typedef struct MyVector3
{
	float x;
	float y;
	float z;
	MyVector3() { x = 0.0f; y = 0.0f; z = 0.0f; }
	MyVector3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {}
	MyVector3 operator - (MyVector3 rbs) const { return MyVector3({ x - rbs.x, y - rbs.y, z - rbs.z }); };
	MyVector3 operator + (MyVector3 rbs) const { return MyVector3({ x + rbs.x, y + rbs.y, z + rbs.z }); };
	MyVector3 operator * (float mul) const { return MyVector3({ x * mul, y * mul, z * mul}); };
	MyVector3 operator / (float div) const { return MyVector3({ x / div, y / div, z / div }); };

	const void operator -= (MyVector3 rbs) { x -= rbs.x; y -= rbs.y; z -= rbs.z; };
	void operator += (MyVector3 rbs) { x += rbs.x; y += rbs.y; z += rbs.z; };
	void operator *= (float mul) { x *= mul; y *= mul; z *= mul; };
	void operator /= (float div) { x /= div; y /= div; z /= div; };

}Vector3;