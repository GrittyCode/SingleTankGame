#pragma once
#include "CObject.h"
class CPlayer;

class CObjectManager
{
	SINGLETONE(CObjectManager)
public:
	
	void Init(HWND hWnd);
	void LateInit();
	void Update();
	void LateUpdate();
	void Render();

	HDC m_hdc;
	HWND m_hwnd;
	map <OBJ::OBJ_TYPE,list<CObject*>> GetPointObjMap();
private:
	map <OBJ::OBJ_TYPE, list<CObject*>> m_pMapObj;
	CPlayer* player;
	RECT rt = { 0,0,1280,720 };
	HBITMAP m_hBitmap;
	HDC m_hBitDC;
};

