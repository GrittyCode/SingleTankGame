#pragma once
#include "CObjectManager.h"
#include "CObject.h"
class CCollisionManager
{
	SINGLETONE(CCollisionManager)

public:
	void Init();
	void LateInit() {};
	void Update() {};
	void LateUpdate(OBJ::OBJ_TYPE sourceKey, OBJ::OBJ_TYPE destKey);
	bool CollisionWithBox(RECT& a_Rect, RECT b_Rect);
private:
	map<OBJ::OBJ_TYPE, list<CObject*>>*  m_objectList;
	RECT m_aRect;
	RECT m_bRect;
	bool isCollision = false;
};

