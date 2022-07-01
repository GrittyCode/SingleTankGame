#pragma once
#include "Collider2D.h"

class BoxCollider2D : public Collider2D
{
	//Method
public:
	BoxCollider2D() { SetColliderType(COLLIDER_TYPE::BOX_COLLIDER);  }
	BoxCollider2D(float xSize, float ySize, CObject* obj);
	~BoxCollider2D() {};
	//LIFE CYCLE
public:
	void Init() {};
	void Update();
	void LateUpdate();
	bool CollisionWith(Collider2D* col);
private:
	float m_fxSize;
	float m_fySize;
};
