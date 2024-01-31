#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster() : m_State(MONSTER_MOVE_END)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 4.f, 100.f, 100.f };
	m_fSpeed = 10.f;

	m_State = MONSTER_MOVE_LEFT;
}

void CMonster::Update()
{
	switch (m_State)
	{
	case MONSTER_MOVE_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case MONSTER_MOVE_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	}
	__super::Update_Rect();
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::TransitionState()
{
	switch (m_State)
	{
	case MONSTER_MOVE_LEFT:
		m_State = MONSTER_MOVE_RIGHT;
		break;
	case MONSTER_MOVE_RIGHT:
		m_State = MONSTER_MOVE_LEFT;
		break;
	case MONSTER_MOVE_END:
		break;
	default:
		break;
	}
}
