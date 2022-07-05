#pragma once
class CircleCollider2D : public Collider2D
{
	//Method
public:
	CircleCollider2D() { SetColliderType(COLLIDER_TYPE::BOX_COLLIDER); m_radius = 1.0f; m_Object = nullptr; }
	CircleCollider2D(float radius, CObject* obj);
	~CircleCollider2D() {};	
//LIFE CYCLE
public:
	void Init() {};
	int Update();
	int LateUpdate();
private:
	float m_radius;
};

