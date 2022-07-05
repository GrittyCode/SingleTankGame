#pragma once
#define  KEY_LEFT 0x00000001
#define  KEY_RIGHT 0x00000010
#define  KEY_SPACE 0x00000100
class InputKeyBoard : public Component
{
public:
	enum class KEY_STATE
	{
		LEFT_ARROW,
		RIGHT_ARROW,
		SPACE,
		KEY_STATE_END
	};

//CONSTRUCTOR
public:
	InputKeyBoard() {}
	~InputKeyBoard() {}

//LIFE CYCLE
public:
	virtual int Update() override;
	virtual int LateUpdate() override;
	virtual void Init() override;
	virtual void Render(HDC hdc) override {};
	int KeyEventUpdate();
private:
	static char m_str[256];
	int m_KeyState = -1;
	DWORD iKeyInput = 0x00000000;
};

