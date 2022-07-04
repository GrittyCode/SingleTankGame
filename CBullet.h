#pragma once
class CBullet : public CObject
{
private:
	CBullet(Vector2 posVec, Vector2 sizeVec, Vector2 lookVec);
	~CBullet();
public:
	void Init();
	static CBullet* Create(Vector2 posVec, Vector2 sizeVec, Vector2 lookVec);
	int Update();
	int LateUpdate();
	void Render(HDC hdc);
};

