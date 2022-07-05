#include "stdfx.h"
#include "CBullet.h"
#include "CObject.h"

void CBullet::Init()
{
}
CBullet::CBullet(Vector2 posVec,  Vector2 lookVec, float speed)
{
	transform->SetPosition(posVec);
	transform->SetSizeVec(m_radius,m_radius);
	transform->SetLookVec(lookVec);
  	transform->SetSpeed(speed);
	AddComponent(L"BoxCollide2D", new BoxCollider2D(transform->GetSizeVec().x, transform->GetSizeVec().y, this));
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
	m_curTime += TimeManager::GetInst()->GetDeltaTime();
	if (m_fliveTime < m_curTime)
	{
		cout << "총알 존재 시간 초과\n";
		m_Obj_Collision = OBJ_COLLISION;
		return m_Obj_Collision;

	}


	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		m_Obj_Collision = (*it).second->LateUpdate();
	}
	return m_Obj_Collision;
}

void CBullet::Render(HDC hdc)
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->Render(hdc);
	}

	Vector2 posVec = transform->GetPosition();
	Ellipse(hdc, posVec.x - m_radius, posVec.y - m_radius,
				 posVec.x + m_radius, posVec.y + m_radius);
}
