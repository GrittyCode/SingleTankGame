#include "stdfx.h"
#include "CPlayer.h"

void CPlayer::Update()
{
}

int CPlayer::LateUpdate() //충돌 처리된 상태에 따라 define된 OBJ_ERR, OBJ_NOEVENT등을 반환하도록 한다.
{
	return false;
}

void CPlayer::Render()
{
}
