#include "stdfx.h"
#include "CMonster.h"


CMonster::CMonster(Vector2 posVec, Vector2 lookVec, float m_speed)
{
	transform->SetSizeVec(70.0f, 70.0f);
	transform->SetPosition(posVec);
	transform->SetLookVec(lookVec);
	transform->SetSpeed(m_speed);
	degree = transform->GetAngle();
}

CMonster* CMonster::Create(Vector2 posVec, Vector2 lookVec, float speed)
{
	CMonster* monster = new CMonster(posVec, lookVec, speed);
	return monster;
}

void CMonster::Init()
{
}

int CMonster::Update()
{
	degree += 60.0f * TimeManager::GetInst()->GetDeltaTime();
	if (degree >= 359.0f)
		degree = 0.0f;
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->Update();
	}
	return 0;
}

int CMonster::LateUpdate()
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->LateUpdate();
	}
	return 0;
}


void CMonster::Render(HDC hdc)
{
	float fDegreeInterval = 360.f / (float)5;
	float fDegree = degree;

	Vector2* pStarArr = new Vector2[5 * 2];

	for (int i = 0; i < 5 * 2; i += 2)
	{
		float x = (cosf(DEGREETORADIAN(fDegree)) * transform->GetRadius() * 0.5f);
		float y = (sinf(DEGREETORADIAN(fDegree)) * transform->GetRadius() * 0.5f);

		pStarArr[i] = { transform->GetPositionX() + x , transform->GetPositionY() + y };

		fDegree += fDegreeInterval;
	}

	fDegree = degree + (fDegreeInterval * 0.5f);
	float distance =
		(cosf(DEGREETORADIAN(fDegreeInterval)) * transform->GetRadius() * 0.5f) / cosf(DEGREETORADIAN(fDegreeInterval * 0.5f));

	for (int i = 1; i < 5 * 2; i += 2)
	{
		float x = (cosf(DEGREETORADIAN(fDegree)) * distance);
		float y = (sinf(DEGREETORADIAN(fDegree)) * distance);

		pStarArr[i] = { transform->GetPositionX() + x , transform->GetPositionY() + y };

		fDegree += fDegreeInterval;
	}

	MoveToEx(hdc, (int)pStarArr[0].x, (int)pStarArr[0].y, nullptr);
	for (int i = 1; i < 5 * 2; ++i)
	{
		LineTo(hdc, (int)pStarArr[i].x, (int)pStarArr[i].y);
	}
	LineTo(hdc, (int)pStarArr[0].x, (int)pStarArr[0].y);

	delete[] pStarArr;
}
