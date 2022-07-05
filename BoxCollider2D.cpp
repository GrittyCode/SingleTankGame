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