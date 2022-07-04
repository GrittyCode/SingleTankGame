#include "stdfx.h"
#include "CBrick.h"
#include "CObject.h"




CBrick::CBrick(Vector2 vecPos, Vector2 vecSize)
{
	 transform->SetPosition(vecPos);
	 transform->SetSizeVec(vecSize.x, vecSize.y);
}



CBrick::~CBrick()
{

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
	return 0;
}

int CBrick::LateUpdate()
{
	return 0;
}

void CBrick::Render(HDC hdc)
{
	Vector2 posVec = transform->GetPosition();

	float xSize = transform->GetSizeX() / 2;
	float ySize = transform->GetSizeY();
	Rectangle(hdc, posVec.x - xSize, posVec.y - ySize, posVec.x + xSize, posVec.y + ySize);
}
