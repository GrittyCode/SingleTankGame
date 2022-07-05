#include "stdfx.h"
#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(float xSize, float ySize, CObject* obj) 
	: m_fxSize(xSize), m_fySize(ySize)
{
	SetColliderType(Collider2D::COLLIDER_TYPE::BOX_COLLIDER);
	m_Object = obj;
}

float BoxCollider2D::GetXSize()
{
	return m_fxSize;
}

float BoxCollider2D::GetYSize()
{
	return m_fySize;
}

//나중에 충돌 범위등을 그릴때 쓸모가 있다.
int BoxCollider2D::Update()
{
	return 0;
}

int BoxCollider2D::LateUpdate()
{
	
	return 0;

}

void BoxCollider2D::Render(HDC hdc)
{
	Rectangle(hdc, ReturnMyVecPos().x - m_fxSize, ReturnMyVecPos().y - m_fySize, ReturnMyVecPos().x + m_fxSize, ReturnMyVecPos().y + m_fySize);
}
