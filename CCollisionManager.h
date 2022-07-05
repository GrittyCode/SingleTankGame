#pragma once
#include "CObjectManager.h"
#include "CObject.h"
class CCollisionManager
{
	//SINGLETONE(CCollisionManager)
public:
	void Init();
	void LateInit();
	void Update();
	void LateUpdate();
private:
	map<OBJ::OBJ_TYPE, list<CObject*>>*  m_objectList;
};

