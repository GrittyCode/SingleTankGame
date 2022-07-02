#pragma once
#include "CObject.h"

class CObject;

class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer() {}
public:
	void Init() {};
	static CPlayer* Create();
	void Update();
	int LateUpdate();
	void Render(HDC hdc);
};

