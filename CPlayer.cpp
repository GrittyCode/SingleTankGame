#include "stdfx.h"
#include "CPlayer.h"

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
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		if ((*it).first == L"InputKeyBoard")
		{
			m_Key = (*it).second->Update();

			switch (m_Key)
			{
			case (int)InputKeyBoard::KEY_STATE::LEFT_ARROW:
				if(transform->GetLookVec().x < 180)
				transform->SetLookVec(1.0f);
				m_Key = (int)InputKeyBoard::KEY_STATE::KEY_STATE_END;
				break;
			case (int)InputKeyBoard::KEY_STATE::RIGHT_ARROW:
				if(transform->GetLookVec().x > 0)
					transform->SetLookVec(-1.0f);
				m_Key = (int)InputKeyBoard::KEY_STATE::KEY_STATE_END;
				break;
			case (int)InputKeyBoard::KEY_STATE::SPACE:
				m_Key = (int)InputKeyBoard::KEY_STATE::SPACE;
				break;
			default:
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
	Vector2 bench = (transform->GetLookVec() * radius);
	Vector2 position[4];
	for (int i = 0; i < 4; ++i)
	{
		position[i].x = bench.x + cosf(DEGREETORADIAN(transform->GetAngle() + (90 * i)));
		position[i].y = bench.y + sinf(DEGREETORADIAN(transform->GetAngle() + (90 * i)));
	}

	MoveToEx(hdc, position[0].x, position[0].y, NULL);
	for (int i = 1; i < 4; ++i)
	{
		LineTo(hdc, position[i].x, position[i].y);
	}
	LineTo(hdc, position[0].x, position[0].y);


	Ellipse(hdc, posVec.x - radius, posVec.y - radius, posVec.x + radius, posVec.y + radius);
	
}
