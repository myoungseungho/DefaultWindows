#include "stdafx.h"
#include "Mouse.h"

CMouse::CMouse()
{
}

CMouse::~CMouse()
{
}

void CMouse::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
}

int CMouse::Update()
{
	POINT ptMouse{};
	GetCursorPos(&ptMouse);
	// 전체 스크린 영역에서 클라이언트 창 좌표로 변환
	ScreenToClient(g_hWnd, &ptMouse);

	m_tInfo.fX = (float)ptMouse.x;
	m_tInfo.fY = (float)ptMouse.y;

	ShowCursor(FALSE);

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CMouse::Late_Update()
{
	// 2. 몬스터
	for (auto iter = m_pMonsterCopy->begin();iter != m_pMonsterCopy->end();++iter)
	{
		const RECT* pRect = &(*iter)->Get_RECT();
		RECT testRC;
		if (IntersectRect(&testRC, pRect, &m_tRect))
		{
			(*iter)->Update_Die();
		}
	}
}

void CMouse::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMouse::Release()
{
}

void CMouse::SetMonster(list<CObj*>* _pMonsterCopy)
{
	m_pMonsterCopy = _pMonsterCopy;
}
