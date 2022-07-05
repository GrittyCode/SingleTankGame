#include "stdfx.h"
#include "InputKeyBoard.h"
#include "Component.h"

int InputKeyBoard::Update()
{
	m_KeyState = KeyEventUpdate();
	return iKeyInput;
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
	iKeyInput = 0;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		iKeyInput |= 0x00000001;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		iKeyInput |= 0x00000010;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		iKeyInput |= 0x00000100;
	}

	return iKeyInput;
}
