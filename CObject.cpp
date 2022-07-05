#include "stdfx.h"
#include "CObject.h"

CObject::CObject()
{
	AddComponent(L"Transform", new Transform2D());
	map<wstring, Component*>::iterator it = m_componentMap.find(L"Transform");

	transform = dynamic_cast<Transform2D*>((*it).second);
}

CObject::~CObject()
{
	delete transform;
}
map<wstring, Component*>* CObject::GetComponentList()
{
	return &m_componentMap;
}
//componet insert method
bool CObject::AddComponent(wstring key, Component* component)
{
	if (m_componentMap.find(key) != m_componentMap.end())
	{
		delete component;
		component = nullptr;
		return false;
	}
	else
	{
		m_componentMap.insert({ key,component });
		return true;
	}
	return false;
}

Transform2D* CObject::GetTransform()
{
	map<wstring, Component*>::iterator it = m_componentMap.find(L"Transform");
	if (it != m_componentMap.end())
	{
		Transform2D* tf = dynamic_cast<Transform2D*>((it->second));
		//찾았다면
		transform = tf;
		return transform;
	}
	
	return nullptr;
}

