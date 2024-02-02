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
		break;
	case DIR_UP:
		m_tInfo.fX += (m_DesX - m_InitX) / 100 * m_fSpeed;
		m_tInfo.fY += (m_DesY - m_InitY) / 100 * m_fSpeed;
		break;
	case DIR_RIGHT:
		break;
	case DIR_DOWN:
		m_tInfo.fX -= (m_DesX - m_InitX) / 100 * m_fSpeed;
		m_tInfo.fY -= (m_DesY - m_InitY) / 100 * m_fSpeed;
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
	//충돌조건
	// 1. 박스 사각형
	if (m_tRect.left <= (WINCX - WINCX_SMALL) * 0.5 || m_tRect.right >= WINCX - ((WINCX - WINCX_SMALL) * 0.5)
		|| m_tRect.top <= (WINCY - WINCY_SMALL) * 0.5 || m_tRect.bottom >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
		m_bDead = true;
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

void CBullet::SetDestination(float x, float y)
{
	m_DesX = x;
	m_DesY = y;
	m_InitX = m_tInfo.fX;
	m_InitY = m_tInfo.fY;
}

