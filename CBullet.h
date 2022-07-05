#pragma once
class CBullet : public CObject
{
private:
	CBullet(Vector2 posVec, Vector2 lookVec, float speed);
	~CBullet() { delete this; };
public:
	void Init();
	static CBullet* Create(Vector2 posVec, Vector2 lookVec, float speed);
	int Update();
	int LateUpdate();
	void Render(HDC hdc);
private:
	float m_radius = 10.0f;
	float m_fliveTime = 2.0f;
	float m_curTime = 0.0f;
};

