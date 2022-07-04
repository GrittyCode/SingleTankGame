#pragma once

class Transform2D : public Component
{
//Method
public:
	Transform2D() {};
	Transform2D(Vector2 posVec, Vector2 sizeVec);
	Transform2D(Vector2 posVec, float xSize, float ySize, float fAngle, float fSpeed);
	Transform2D(float x, float y, float xSize, float ySize, float fAngle, float fSpeed);
	/// <summary>
	/// x = posVec x좌표 y = posVec y좌표
	/// </summary>
	Transform2D* Create(Vector2 posVec, float xSize, float ySize, float fAngle, float fSpeed);
	Transform2D* Create(float x, float y, float xSize, float ySize, float fAngle, float fSpeed);
	void SetSpeed(float speed);
	void SetPosition(int x, int y);
	void SetPosition(Vector2 vec);
	void SetSizeVec(Vector2 vec);
	void SetSizeVec(float xSize, float ySize);
	Vector2 GetLookVec();
	void SetLookVec(float fangle);
	void MoveToLookVec();
	Vector2 GetPosition() const;
	Vector2 GetRotation() const;
	float GetPositionX() const;
	float GetPositionY() const;
	float GetRotationX() const;
	float GetRotationY() const;
	float GetRadius() const;
	Vector2 GetSizeVec() const;
	float GetSizeX() const;
	float GetSizeY() const;
	float GetAngle() const;
//LIFE CYCLE
public :
	void Init() {};
	int Update() { return 0; };
	int LateUpdate() { return 0; };
private:
	//위치 벡터
	Vector2 m_posVec;
	//회전값 벡터
	Vector3 m_rotVec;
	//현재 어느 위치를 바라보고 있는지 확인하는 벡터
	Vector2 m_LookVec;
	Vector2 m_SizeVec;
	float m_fAngle = 0.0f;
	float m_fSpeed = 0.0f;
};

