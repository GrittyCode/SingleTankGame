#pragma once
#include "CObject.h"

class CObject;

class CPlayer : public CObject
{
public:
	CPlayer() { delete this; };
	CPlayer(Vector2 posVec, Vector2 sizeVec);
	~CPlayer() {}
public:
	void Init();
	static CPlayer* Create(Vector2 posVec, Vector2 sizeVec);
	int Update();
	int LateUpdate();
	void Render(HDC hdc);
private:
	//keyboard상태를 담는 m_key
	int m_Key;
	float m_Xsize = 10;
	float m_Ysize = 100;
	float m_fdelayTime = 0.2f;
	float m_curTime = 0.0f;
	Vector2 bench;
};

