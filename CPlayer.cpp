#include "stdfx.h"

#include "CPlayer.h"
#include "TimeManager.h"


CPlayer::CPlayer(Vector2 posVec, Vector2 sizeVec)
{
	transform->SetPosition(posVec);
	transform->SetSizeVec(sizeVec);
	transform->SetLookVec(90.0f);
}

void CPlayer::Init()
{
	AddComponent(L"InputKeyBoard", new InputKeyBoard());
}

CPlayer* CPlayer::Create(Vector2 posVec, Vector2 sizeVec)
{
	CPlayer* player = new CPlayer(posVec, sizeVec);
	return player;
}

int CPlayer::Update()
{
	m_curTime += TimeManager::GetInst()->GetDeltaTime();
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		if ((*it).first == L"InputKeyBoard")
		{
			m_Key = (*it).second->Update();

			if ((m_Key & KEY_RIGHT) == KEY_RIGHT)
			{
				if (transform->GetAngle() < 179.0f)
					transform->SetLookVec(0.1f);
			}

			if ((m_Key & KEY_LEFT) == KEY_LEFT)
			{
				if (transform->GetAngle() > 1.0f)
					transform->SetLookVec(-0.1f);
			}

			if ((m_Key & KEY_SPACE) == KEY_SPACE)
			{
				m_Key = (int)InputKeyBoard::KEY_STATE::SPACE;

				if (m_curTime >= m_fdelayTime)
				{
					map <OBJ::OBJ_TYPE, list<CObject*>>::iterator it;
					it = CObjectManager::GetInst()->GetPointObjMap()->find(OBJ::OBJ_TYPE::BULLET);
					(*it).second.push_back(CBullet::Create(bench, transform->GetLookVec(), 400.0f));
					m_curTime = 0.0f;
				}
			}
			else
			{
				m_Key = (int)InputKeyBoard::KEY_STATE::KEY_STATE_END;
				break;
			}
		}
		else
		{
			(*it).second->Update();
		}		
	}

	return m_Key;
}

int CPlayer::LateUpdate() //충돌 처리된 상태에 따라 define된 OBJ_ERR, OBJ_NOEVENT등을 반환하도록 한다.
{

	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->LateUpdate();
	}
	return 0;
}

void CPlayer::Render(HDC hdc)
{
	Vector2 posVec = transform->GetPosition();
	float radius = transform->GetRadius();
	bench = (transform->GetLookVec() * radius) + posVec;

	MoveToEx(hdc, bench.x, bench.y, nullptr);

	bench = (transform->GetLookVec() * 1.5f * radius) + posVec;

	LineTo(hdc, bench.x, bench.y);


	Ellipse(hdc, (int)(posVec.x - radius), (int)(posVec.y - radius), (int)(posVec.x + radius), (int)(posVec.y + radius));
	
}
