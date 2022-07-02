#include "stdfx.h"
#include "CPlayer.h"

CPlayer::CPlayer(Vector2 posVec, Vector2 sizeVec)
{
	transform->SetPosition(posVec);
	transform->SetSizeVec(sizeVec);
}

void CPlayer::Init()
{
}

CPlayer* CPlayer::Create(Vector2 posVec, Vector2 sizeVec)
{
	CPlayer* player = new CPlayer(posVec, sizeVec);
	return player;
}

void CPlayer::Update()
{
	for (map<wstring, Component*>::iterator it; it != m_componentMap.end(); ++it)
	{
		(*it).second->Update();
	}
}

int CPlayer::LateUpdate() //충돌 처리된 상태에 따라 define된 OBJ_ERR, OBJ_NOEVENT등을 반환하도록 한다.
{

	for (map<wstring, Component*>::iterator it; it != m_componentMap.end(); ++it)
	{
		(*it).second->LateUpdate();
	}
	return false;
}

void CPlayer::Render(HDC hdc)
{
	Vector2 posVec = transform->GetPosition();
	float radius = transform->GetRadius();
	printf("내 위치 X 크기는 -> %lf\n", posVec.x);
	printf("내 반지름 크기는 -> %lf\n", radius);
	Ellipse(hdc, posVec.x - radius, posVec.y - radius, posVec.x + radius, posVec.y + radius);
}
