#include "stdfx.h"
#include "CircleCollider2D.h"
#include "Collider2D.h"

CircleCollider2D::CircleCollider2D(float radius, CObject* obj)
{
	SetColliderType(COLLIDER_TYPE::CIRCLE_COLLIDER);
	m_radius = radius;
	m_Object = obj;
}

int CircleCollider2D::Update()
{
	return 0;
}

int CircleCollider2D::LateUpdate()
{
	return 0;
}
