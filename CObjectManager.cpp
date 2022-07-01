#include "stdfx.h"
#include "CObjectManager.h"
#include "CObject.h"

std::map<OBJ::OBJ_TYPE, std::list<CObject*>> CObjectManager::GetPointObjMap()
{
	return std::map<OBJ::OBJ_TYPE, std::list<CObject*>>();
}
