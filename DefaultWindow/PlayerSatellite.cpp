#include "stdafx.h"
#include "PlayerSatellite.h"


CPlayerSatellite::CPlayerSatellite() : m_fBigRadius(0.f), m_fDegree(0.f), m_degreeCount(1), m_pPlayerCopy(nullptr), m_fSmallRadius(0.f)
{
}

CPlayerSatellite::~CPlayerSatellite()
{
}

void CPlayerSatellite::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fDegree = (2 * PI) / 180.f;
	m_directionX = m_tInfo.fX;
	m_directionY = m_tInfo.fY - m_fBigRadius;
}

int CPlayerSatellite::Update()
{
	m_degreeCount++;

	m_directionX = (m_pPlayerCopy->Get_Info().fX) - m_fBigRadius * sin(m_fDegree * m_degreeCount);
	m_directionY = (m_pPlayerCopy->Get_Info().fY) - m_fBigRadius * cos(m_fDegree * m_degreeCount);

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CPlayerSatellite::Late_Update()
{
}

void CPlayerSatellite::Render(HDC hDC)
{
	Ellipse(hDC, m_directionX - m_fSmallRadius, m_directionY - m_fSmallRadius, m_directionX + m_fSmallRadius, m_directionY + m_fSmallRadius);
}

void CPlayerSatellite::Release()
{
}

void CPlayerSatellite::SetPlayer(CObj* _pPlayer)
{
	m_pPlayerCopy = _pPlayer;

	m_fBigRadius = (m_pPlayerCopy->Get_Info().fCX);
	m_fSmallRadius = (m_pPlayerCopy->Get_Info().fCX) * 0.1f;
}
