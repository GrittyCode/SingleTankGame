#pragma once
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
	int KeyEventUpdate();
private:
	static char m_str[256];
	int m_KeyState = -1;
};

