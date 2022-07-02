#include "stdfx.h"
#include "CObjectManager.h"
#include "CObject.h"

CObjectManager* CObjectManager::m_pInst = nullptr;

void CObjectManager::Init(HWND hWnd)
{

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	m_hwnd = hWnd;
	m_hdc = GetDC(m_hwnd);
	m_hBitmap = CreateCompatibleBitmap(m_hdc, rt.right, rt.bottom);
	m_hBitDC = CreateCompatibleDC(m_hdc);

	// �̰� �� �־�� �ϳ�?
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_hBitDC, m_hBitmap);
	DeleteObject(hOldBit);
	
	//
}

void CObjectManager::LateInit()
{
	//Player Instance
	player = CPlayer::Create();
	//Brick Instance

	map <OBJ::OBJ_TYPE, list<CObject*>>::iterator it = m_pMapObj.find(OBJ::OBJ_TYPE::BRICK);
	if (it == m_pMapObj.end())
	{
		m_pMapObj.insert({ OBJ::OBJ_TYPE::BRICK, list<CObject*>() });
		it = m_pMapObj.find(OBJ::OBJ_TYPE::BRICK);
		float brickXSize = 160;
		float brickYSize = 10;
		float brickYoffset = 20;
		float middleXSize = brickXSize / 2;
		//�� 8�� ����
		for (int i = 0; i < 8; ++i)
		{
			float Posx = (float)(brickXSize * i) + middleXSize;
			
			//posvec, sizevec
			(*it).second.push_back((CBrick::Create({ Posx, (float)rt.bottom - brickYoffset }, { brickXSize,brickYSize })));
		}
	}
}

void CObjectManager::Update()
{
}

void CObjectManager::LateUpdate()
{
}

void CObjectManager::Render()
{
	Rectangle(m_hBitDC, -1, -1, rt.right + 1, rt.bottom + 1);

	for (int i = (int)OBJ::OBJ_TYPE::BRICK; i < (int)OBJ::OBJ_TYPE::OBJ_TYPE_END; ++i)
	{
		map<OBJ::OBJ_TYPE, list<CObject*>>::iterator iter_map = m_pMapObj.find((OBJ::OBJ_TYPE)i);
		if (iter_map == m_pMapObj.end())
			continue;

		for(list<CObject*>::iterator it = iter_map->second.begin(); it != iter_map->second.end(); ++it)
		{
			(*it)->Render(m_hBitDC);
		}
	}

	BitBlt(m_hdc, 0, 0, rt.right, rt.bottom, m_hBitDC, 0, 0, SRCCOPY);
}

std::map<OBJ::OBJ_TYPE, std::list<CObject*>> CObjectManager::GetPointObjMap()
{
	return std::map<OBJ::OBJ_TYPE, std::list<CObject*>>();
}