#include "stdfx.h"
#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(float xSize, float ySize, CObject* obj) 
	: m_fxSize(xSize), m_fySize(ySize)
{
	SetColliderType(Collider2D::COLLIDER_TYPE::BOX_COLLIDER);
	m_Object = obj;
}

void BoxCollider2D::Update()
{
}

void BoxCollider2D::LateUpdate()
{
}

bool BoxCollider2D::CollisionWith(Collider2D* col)
{
	switch (col->GetColliderType())
	{
		//rect�������� �浹 ó��
	case Collider2D::COLLIDER_TYPE::BOX_COLLIDER:
	{
	}
	break;
	//���� �ڽ��� �浹
	case Collider2D::COLLIDER_TYPE::CIRCLE_COLLIDER:
		break;

	default:
		return false;
		break;
	}

	return false;
}