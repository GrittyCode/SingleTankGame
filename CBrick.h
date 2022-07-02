#pragma once

#include "CObject.h"

class CBrick : public CObject
{
public:
	CBrick(Vector2 vecPos, Vector2 vecSiz);
	~CBrick();
	static CBrick* Create(Vector2 vecPos, Vector2 vecSize);
	
	virtual void Init() override;
	virtual void Update() override;
	virtual int LateUpdate() override;
	virtual void Render(HDC hdc) override;
	Vector2 m_Collision;private:
private:
	int m_hp = 3;
};

