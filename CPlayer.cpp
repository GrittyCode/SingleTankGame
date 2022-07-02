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

int CPlayer::LateUpdate() //�浹 ó���� ���¿� ���� define�� OBJ_ERR, OBJ_NOEVENT���� ��ȯ�ϵ��� �Ѵ�.
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
	printf("�� ��ġ X ũ��� -> %lf\n", posVec.x);
	printf("�� ������ ũ��� -> %lf\n", radius);
	Ellipse(hdc, posVec.x - radius, posVec.y - radius, posVec.x + radius, posVec.y + radius);
}
