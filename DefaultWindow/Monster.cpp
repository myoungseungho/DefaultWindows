#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster() :m_pPlayerCopy(nullptr)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 4.f, 100.f, 100.f };
	m_fSpeed = 1.f;
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	double atan2Value = atan2(m_pPlayerCopy->Get_Info().fY - m_tInfo.fY, m_pPlayerCopy->Get_Info().fX - m_tInfo.fX);

	m_tInfo.fX += m_fSpeed * cos(atan2Value);
	m_tInfo.fY += m_fSpeed * sin(atan2Value);


	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	//Left, Top, Right, Bottom
	//if ((m_tRect.left <= (WINCX - WINCX_SMALL) * 0.5) || m_tRect.right >= WINCX - ((WINCX - WINCX_SMALL) * 0.5))
	//	m_fSpeed *= -1.f;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::SetPlayer(CObj* _pPlayer)
{
	m_pPlayerCopy = _pPlayer;
}


