#pragma once
#include "CObject.h"
class CObjectManager
{
	SINGLETONE(CObjectManager)
public:
	void Update();
	void LateUpdate();
	void Render();
	map < OBJ::OBJ_TYPE, std::list<CObject*>> GetPointObjMap();
private:
	map < OBJ::OBJ_TYPE, std::list<CObject*>> m_pMapObj;

};

