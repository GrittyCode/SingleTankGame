#include "stdfx.h"
#include "CBrick.h"
#include "CObject.h"



CBrick::CBrick(Vector2 vecPos, Vector2 vecSize)
{
	 transform->SetPosition(vecPos);
	 transform->SetSizeVec(vecSize.x, vecSize.y);
	 AddComponent(L"BoxCollide2D", new BoxCollider2D(transform->GetSizeVec().x, transform->GetSizeVec().y, this));
}


CBrick::~CBrick()
{
	delete this;
}

void CBrick::Init()
{
	
}

CBrick* CBrick::Create(Vector2 vecPos, Vector2 vecSize)
{
	CBrick* brick = new CBrick(vecPos, vecSize);
	return brick;
}

int CBrick::Update()
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->Update();
	}
	return 0;
}

int CBrick::LateUpdate()
{
	for (map<wstring, Component*>::iterator it = m_componentMap.begin(); it != m_componentMap.end(); ++it)
	{
		(*it).second->LateUpdate();
	}
	return ReturnObjState();
}

void CBrick::Render(HDC hdc)
{
	

	Vector2 posVec = transform->GetPosition();
	float xSize = transform->GetSizeX() / 2;
	float ySize = transform->GetSizeY();
	Rectangle(hdc, posVec.x - xSize, posVec.y - ySize, posVec.x + xSize, posVec.y + ySize);
}
