#include "stdfx.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_type = OBJ::OBJ_TYPE::PLAYER;
	AddComponent(L"Transform", transform = new Transform2D(0, 0, 10, 10, 0, 0));
}

CPlayer* CPlayer::Create()
{
	CPlayer* player = new CPlayer();
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
	Vector2 posVec = GetTransform()->GetPosition();
	float radius = GetTransform()->GetRadius();
	Ellipse(hdc, posVec.x - radius, posVec.y - radius, posVec.x + radius, posVec.y + radius);
}
