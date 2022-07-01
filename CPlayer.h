#pragma once

#include "CObject.h"
class CPlayer : public CObject
{
public:
	CPlayer() { m_type = OBJ::OBJ_TYPE::PLAYER; }
	~CPlayer() {}
public:
	void Update();
	int LateUpdate();
	void Render();
};

