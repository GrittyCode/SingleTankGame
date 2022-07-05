#include "stdfx.h"
#include "CCollisionManager.h"

void CCollisionManager::Init()
{
	m_objectList = CObjectManager::GetInst()->GetPointObjMap();
}

void CCollisionManager::LateInit()
{
}

void CCollisionManager::Update()
{
	
}

void CCollisionManager::LateUpdate()
{
	for (int i = (int)OBJ::OBJ_TYPE::BULLET; i < (int)OBJ::OBJ_TYPE::OBJ_TYPE_END; ++i)
	{
		map<OBJ::OBJ_TYPE, list<CObject*>>::iterator iter_map = m_objectList->find((OBJ::OBJ_TYPE)i);

		if (iter_map == m_objectList->end())
			continue;

		for (list<CObject*>::iterator it = iter_map->second.begin(); it != iter_map->second.end(); ++it)
		{
			for (map<wstring, Component*>::iterator it2 = (*it)->GetComponentList()->begin(); it2 != (*it)->GetComponentList()->end(); it2++)
			{
				if ((*it)->GetComponentList()->find(L"BoxCollide2D") != (*it)->GetComponentList()->end())
				{

				}
				if ((*it)->GetComponentList()->find(L"CircleCollide2D") != (*it)->GetComponentList()->end())
				{

				}
			}
		
		}
	}

}

