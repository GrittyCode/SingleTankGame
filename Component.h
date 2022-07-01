#pragma once

class Component
{
public:
//持失社瑚切
public:
	Component() {}
	~Component() {}
//LIFE CYCLE
public:
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Init() = 0;
private:
};

