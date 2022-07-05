#pragma once
#include "Collider2D.h"

class BoxCollider2D : public Collider2D
{
	//Method
public:
	BoxCollider2D() { SetColliderType(COLLIDER_TYPE::BOX_COLLIDER);  }
	BoxCollider2D(float xSize, float ySize, CObject* obj);
	~BoxCollider2D() {};
	float GetXSize();
	float GetYSize();
	//LIFE CYCLE
public:
	void Init() {};
	int Update();
	int LateUpdate();
	void Render(HDC hdc);
private:
	//���� + m_fxsize , ���� - m_fxsize, ���� + m_fySize, ���� - m_fySize �ȿ� �����ִ� �ݶ��̴��� ���� �� �浹��.
	//�浹�� ���(�ݸ����Ŵ����� ó��) m_Obj_Collision = OBJ_COLLISION ���·� �ٲ��ش�. �׷��ٸ� CollisionManager�� LateUpdate���� return ���� �����ν�
	//������Ʈ���� �ݸ��� ���¸� �ٲ��ְ� �� ������ ������ ���� ������Ʈ �Ŵ����� LATEUPDATE���� ���������� ó��(���� or ����)���ش�. 
	float m_fxSize;
	float m_fySize;
};
