#include "stdfx.h"
#include "Transform.h"


Transform2D::Transform2D(Vector2 posVec, float fAngle, float fSpeed)
{
	m_posVec = posVec;
	m_fAngle = fAngle;
	m_fSpeed = fSpeed;
}

Transform2D::Transform2D(float x, float y,float fAngle, float fSpeed)
{
	this->m_posVec.x = x;
	this->m_posVec.y = y;
	m_fAngle = fAngle;
	m_fSpeed = fSpeed;
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
