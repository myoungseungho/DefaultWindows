#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet(BULLETMODE _bulletMode) :m_FirePositionX(0.f), m_FirePositionY(0.f), m_fDegree(0.f), m_fSmallRadius(0.f),
m_directionX(0.f), m_directionY(0.f), m_degreeCount(1)
{
	m_BulletMode = _bulletMode;
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fSpeed = 0.05f;
	m_fDegree = (20 * PI) / 180.f;
	m_fSmallRadius = m_tInfo.fCX * 0.5f;

	m_directionX = m_tInfo.fX - m_fSmallRadius * sin(m_fDegree * m_degreeCount);
	m_directionY = m_tInfo.fY - m_fSmallRadius * cos(m_fDegree * m_degreeCount);
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
		m_tInfo.fX -= (m_PlayerX - m_FirePositionX) * m_fSpeed;
		m_tInfo.fY -= (m_PlayerY - m_FirePositionY) * m_fSpeed;
		break;
	case DIR_RIGHT:
		break;
	case DIR_DOWN:
		m_tInfo.fX += (m_PlayerX - m_FirePositionX) * m_fSpeed;
		m_tInfo.fY += (m_PlayerY - m_FirePositionY) * m_fSpeed;
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

	m_degreeCount++;
	m_directionX = m_tInfo.fX - m_fSmallRadius * sin(m_fDegree * m_degreeCount);
	m_directionY = m_tInfo.fY - m_fSmallRadius * cos(m_fDegree * m_degreeCount);

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
	switch (m_BulletMode)
	{
	case BULLET_NORMAL:
		Ellipse(hDC,
			m_tRect.left,
			m_tRect.top,
			m_tRect.right,
			m_tRect.bottom);
		break;
	case BULLET_SCREW:
		Ellipse(hDC,
			m_directionX - m_fSmallRadius,
			m_directionY - m_fSmallRadius,
			m_directionX + m_fSmallRadius,
			m_directionY + m_fSmallRadius);
		break;
	case BULLET_END:
		break;
	default:
		break;
	}
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
	m_PlayerX = x;
	m_PlayerY = y;

	m_FirePositionX = m_tInfo.fX;
	m_FirePositionY = m_tInfo.fY;
}

