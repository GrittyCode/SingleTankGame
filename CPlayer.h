#pragma once
#include "CObject.h"

class CObject;

class CPlayer : public CObject
{
public:
	CPlayer() {};
	CPlayer(Vector2 posVec, Vector2 sizeVec);
	~CPlayer() {}
public:
	void Init();
	static CPlayer* Create(Vector2 posVec, Vector2 sizeVec);
	void Update();
	int LateUpdate();
	void Render(HDC hdc);
};

