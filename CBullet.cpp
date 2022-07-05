#include "stdfx.h"
#include "CBullet.h"
#include "CObject.h"

void CBullet::Init()
{
}
CBullet::CBullet(Vector2 posVec,  Vector2 lookVec, float speed)
{
	AddComponent(L"CircleCollide2D", new CircleCollider2D(m_radius,this));
	transform->SetPosition(posVec);
	transform->SetSizeVec(m_radius,m_radius);
	transform->SetLookVec(lookVec);
  	transform->SetSpeed(speed);
}
CBullet* CBullet::Create(Vector2 posVec, Vector2 lookVec, float speed)
{
	CBullet* bullet = new CBullet(posVec , lookVec , speed);
	return bullet;
}

int CBullet::Update()
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->Update();
	}
	return 0;
}

int CBullet::LateUpdate()
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		m_Obj_Collision = (*it).second->LateUpdate();
	}
	return m_Obj_Collision;
}

void CBullet::Render(HDC hdc)
{
	Vector2 posVec = transform->GetPosition();
	Ellipse(hdc, posVec.x - m_radius, posVec.y - m_radius,
				 posVec.x + m_radius, posVec.y + m_radius);
}
