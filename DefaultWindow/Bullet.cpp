#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fSpeed = 3.f;
}

int CBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_LUP:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_RUP:
		m_tInfo.fY -= m_fSpeed;
		m_tInfo.fX += m_fSpeed;
		break;
	case DIR_LDOWN:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_RDOWN:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_END:
		break;
	default:
		break;
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	////충돌조건
	//// 1. 박스 사각형
	//if (m_tRect.left <= (WINCX - WINCX_SMALL) * 0.5 || m_tRect.right >= WINCX - ((WINCX - WINCX_SMALL) * 0.5)
	//	|| m_tRect.top <= (WINCY - WINCY_SMALL) * 0.5 || m_tRect.bottom >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
	//	m_bDead = true;

	//// 2. 몬스터
	//for (auto iter = m_pMonsterCopy->begin();iter != m_pMonsterCopy->end();++iter)
	//{
	//	const RECT* pRect = &(*iter)->Get_RECT();
	//	RECT testRC;
	//	if (IntersectRect(&testRC, pRect ,&m_tRect))
	//	{
	//		(*iter)->Update_Die();
	//		m_bDead = true;
	//	}
	//}
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::SetMonster(list<CObj*>* _pMonsterCopy)
{
	m_pMonsterCopy = _pMonsterCopy;
}

