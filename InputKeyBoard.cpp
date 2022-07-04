#include "stdfx.h"
#include "InputKeyBoard.h"
#include "Component.h"

int InputKeyBoard::Update()
{
	m_KeyState = KeyEventUpdate();
	return m_KeyState;
}

int InputKeyBoard::LateUpdate()
{
	return 0;
}

void InputKeyBoard::Init()
{
}

int InputKeyBoard::KeyEventUpdate()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return (int)KEY_STATE::RIGHT_ARROW;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return (int)KEY_STATE::LEFT_ARROW;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		return (int)KEY_STATE::SPACE;
	}

	return -1;
}
