#include "stdfx.h"
#include "Transform.h"


Transform2D::Transform2D(Vector2 posVec, float xSize, float ySize,  float fAngle, float fSpeed)
{
	m_posVec = posVec;
	m_fAngle = fAngle;
	m_fSpeed = fSpeed;
	this->m_x = xSize;
	this->m_y = ySize;

}

Transform2D::Transform2D(float x, float y, float xSize, float ySize, float fAngle, float fSpeed)
{
	this->m_posVec.x = x;
	this->m_posVec.y = y;
	this->m_x = xSize;
	this->m_y = ySize;
	m_fAngle = fAngle;
	m_fSpeed = fSpeed;
}

Transform2D* Transform2D::Create(Vector2 posVec, float xSize, float ySize, float fAngle, float fSpeed)
{
	m_posVec = posVec;
	this->m_x = xSize;
	this->m_y = ySize;
	m_fAngle = fAngle;
	m_fSpeed = fSpeed;
	return this;
}

Transform2D* Transform2D::Create(float x, float y, float xSize, float ySize, float fAngle, float fSpeed)
{
	Transform2D* transform = new Transform2D();
	return transform;
}

void Transform2D::SetSpeed(float speed)
{
	m_fSpeed = speed;
}

void Transform2D::SetPosition(int x, int y)
{
	m_posVec.x = x;
	m_posVec.y = y;
}

void Transform2D::SetPosition(Vector2 vec)
{
	m_posVec.x = vec.x;
	m_posVec.y = vec.y;
}
void Transform2D::SetSizeVec(Vector2 vec)
{
	m_x = vec.x;
	m_y = vec.y;
}
void Transform2D::SetSizeVec(float xSize, float ySize)
{
	m_x = xSize;
	m_y = ySize;
}
Vector2 Transform2D::GetLookVec()
{
	return m_LookVec;
}

void Transform2D::SetLookVec(float fangle)
{
	m_fAngle += fangle;
	m_LookVec.x = cosf(DEGREETORADIAN(m_fAngle));
	m_LookVec.y = sinf(DEGREETORADIAN(m_fAngle));
}

void Transform2D::MoveToLookVec()
{
	m_posVec.x += m_LookVec.x * m_fSpeed;
	m_posVec.y += m_LookVec.y * m_fSpeed;
}

Vector2 Transform2D::GetPosition() const
{
	return Vector2(m_posVec.x, m_posVec.y);
}

Vector2 Transform2D::GetRotation() const
{
	return Vector2(m_rotVec.x, m_rotVec.y);
}

float Transform2D::GetPositionX() const
{
	return m_posVec.x;
}

float Transform2D::GetPositionY() const
{
	return m_posVec.y;
}

float Transform2D::GetRotationX() const
{
	return m_rotVec.x;
}

float Transform2D::GetRotationY() const
{
	return m_rotVec.y;
}

float Transform2D::GetRadius() const
{
	return m_x;
}

Vector2 Transform2D::GetSizeVec() const
{
	return Vector2(m_x, m_y);
}

float Transform2D::GetSizeX() const
{
	return m_x;
}

float Transform2D::GetSizeY() const
{
	return m_y;
}
