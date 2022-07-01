#pragma once

class Transform2D : public Component
{
//Method
public:
	Transform2D() {};
	Transform2D(Vector2 posVec, float fAngle, float fSpeed);
	Transform2D(float x, float y, float fAngle, float fSpeed);
	/// <summary>
	/// x = posVec x��ǥ y = posVec y��ǥ
	/// </summary>
	void SetSpeed(float speed);
	void SetPosition(int x, int y);
	Vector2 GetLookVec();
	void SetLookVec(float fangle);
	void MoveToLookVec();
	Vector2 GetPosition() const;
	Vector2 GetRotation() const;
	float GetPositionX() const;
	float GetPositionY() const;
	float GetRotationX() const;
	float GetRotationY() const;
//LIFE CYCLE
public :
	void Init() {};
	void Update() {};
	void LateUpdate() {};
private:
	//��ġ ����
	Vector2 m_posVec;
	//ȸ���� ����
	Vector3 m_rotVec;
	//���� ��� ��ġ�� �ٶ󺸰� �ִ��� Ȯ���ϴ� ����
	Vector2 m_LookVec;
	float m_fAngle = 0;
	float m_fSpeed = 0;
};

