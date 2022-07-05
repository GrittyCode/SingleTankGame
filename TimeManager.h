#pragma once

//deltatime�� �������ִ� Ŭ����
//deltatime�̶� �� ��ǻ���� ���ɿ� ���� FPS�� �ٸ����ν� ����� ���� ���̸� ���ֱ� ���� ��.
//��, ��ǻ���� ���ɿ� ���� ����� ���� ���̸� ���ֱ� ���� ���� �ϴ� ��.

/*
  DeltaTime(�����ӻ����� �ð�) =

	  (���� �������� ������ī���� - ���� �������� ������ī����) / �ʴ�������
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

