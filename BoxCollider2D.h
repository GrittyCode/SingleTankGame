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
	//중점 + m_fxsize , 중점 - m_fxsize, 중점 + m_fySize, 중점 - m_fySize 안에 겹쳐있는 콜라이더가 있을 시 충돌됨.
	//충돌된 경우(콜리전매니저가 처리) m_Obj_Collision = OBJ_COLLISION 상태로 바꿔준다. 그렇다면 CollisionManager의 LateUpdate에서 return 값을 줌으로써
	//오브젝트들의 콜리전 상태를 바꿔주고 이 상태의 정보를 통해 오브젝트 매니저의 LATEUPDATE에서 마지막으로 처리(삭제 or 유지)해준다. 
	float m_fxSize;
	float m_fySize;
};
