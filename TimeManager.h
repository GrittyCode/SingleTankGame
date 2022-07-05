#pragma once

//deltatime을 제작해주는 클래스
//deltatime이란 각 컴퓨터의 성능에 따라 FPS가 다름으로써 생기는 값의 차이를 없애기 위한 값.
//즉, 컴퓨터의 성능에 따라 생기는 값의 차이를 없애기 위해 제작 하는 것.

/*
  DeltaTime(프레임사이의 시간) =

	  (현재 프레임의 진동수카운팅 - 이전 프레임의 진동수카운팅) / 초당진동수
*/
class TimeManager
{
	SINGLETONE(TimeManager)
public :
	void Init();
	void Update();
	float GetDeltaTime();

private:
	LARGE_INTEGER periodFrequency;
	float deltaTime = 0.0f;
	LARGE_INTEGER lastTime;
	LARGE_INTEGER curTime;
	LARGE_INTEGER timeScale;
};

