#include "stdfx.h"
#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(float xSize, float ySize, CObject* obj) 
	: m_fxSize(xSize), m_fySize(ySize)
{
	SetColliderType(Collider2D::COLLIDER_TYPE::BOX_COLLIDER);
	m_Object = obj;
}

int BoxCollider2D::Update()
{
	return 0;
}

int BoxCollider2D::LateUpdate()
{
	return 0;

}

bool BoxCollider2D::CollisionWith(Collider2D* col)
{
	switch (col->GetColliderType())
	{
		//rect기준으로 충돌 처리
	case Collider2D::COLLIDER_TYPE::BOX_COLLIDER:
	{
	}
	break;
	//원과 박스의 충돌
	case Collider2D::COLLIDER_TYPE::CIRCLE_COLLIDER:
		break;

	default:
		return false;
		break;
	}

	return false;
}