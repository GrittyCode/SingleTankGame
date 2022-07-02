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
	AddComponent(L"Transform", transform = new Transform2D(0, 0, 10, 10, 0, 0));
}

CBrick* CBrick::Create(Vector2 vecPos, Vector2 vecSize)
{
	CBrick* brick = new CBrick(vecPos, vecSize);
	return brick;
}

void CBrick::Update()
{
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

	printf("내 X좌표는 이거야->%lf\n", posVec.x);
	printf("내 x사이즈는 이거야->%lf", xSize);
	Rectangle(hdc, posVec.x - xSize, posVec.y - ySize, posVec.x + xSize, posVec.y + ySize);
}
