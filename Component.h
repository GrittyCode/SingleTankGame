#pragma once

class Component
{
public:
	Component() {}
	~Component() {}
//LIFE CYCLE
public:
	virtual int Update() = 0;
	virtual int LateUpdate() = 0;
	virtual void Init() = 0;
	virtual void Render(HDC hdc) = 0;
private:
};

