#include "stdfx.h"
#include "TimeManager.h"


TimeManager* TimeManager::m_pInst = nullptr;

void TimeManager::Init()
{
	QueryPerformanceFrequency(&periodFrequency);

	QueryPerformanceCounter(&lastTime);

}

void TimeManager::Update()
{
	QueryPerformanceCounter(&curTime);
	deltaTime = (float)(curTime.QuadPart - lastTime.QuadPart) / periodFrequency.QuadPart;
	
	lastTime = curTime;
}

float TimeManager::GetDeltaTime()
{
	return deltaTime;
}
