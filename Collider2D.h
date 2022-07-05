#pragma once

#include "Component.h"
class CObject;

class Collider2D : public Component
{
//Method
public:
	enum class COLLIDER_TYPE
	{
		BOX_COLLIDER,
		CIRCLE_COLLIDER
	};
	Collider2D()  { };
	~Collider2D() { };
	COLLIDER_TYPE GetColliderType() { return m_type; };
	void SetColliderType(COLLIDER_TYPE type) { m_type = type; }
//LIFECYCLE
public:
	void Init() {};
	Vector2 ReturnMyVecPos();
	int virtual Update() { return 0; };
	int virtual LateUpdate() { return 0; };
	void virtual Render(HDC hdc) { return; };
	bool virtual CollisionWith(Collider2D* col) { return false; };
//VARIABLE
protected: 
		//���� �����ִ� ������Ʈ�� ��ġ�� �޾ƿ��� ���� ������
		CObject* m_Object;
		COLLIDER_TYPE m_type;
};


