#pragma once

#include "Component.h"

class Transform2D;

namespace OBJ
{
	enum class OBJ_TYPE
	{
		PLAYER,
		BULLET,
		ENEMY,
		BRICK,
		OBJ_TYPE_END
	};
}

class CObject
{
//METHOD
public:
	CObject();
	CObject(HDC hdc);
	bool AddComponent(wstring key, Component* component);
	Transform2D* GetTransform();
//LIFECYCLE
public:
	virtual void Init() = 0;
	virtual int Update() = 0;
	virtual int LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	
protected:
	OBJ::OBJ_TYPE m_type;
	map<wstring ,Component*> m_componentMap;
	Transform2D* transform = nullptr;
};

	