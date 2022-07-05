#pragma once
class CMonster : public CObject
{
private:
	CMonster();
	CMonster(Vector2 posVec, Vector2 lookVec, float m_speed);
	~CMonster() {};
	//METHOD
public:
	static CMonster* Create(Vector2 posVec, Vector2 lookVec, float speed);
	//LIFECYCLE
public:
	virtual void Init() override;
	virtual int Update() override;
	virtual int LateUpdate() override;
	virtual void Render(HDC hdc) override;
private:
	float degree;
};

