#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer() :m_pBulletCopy(nullptr), m_degree(0.f), m_degreeCount(0)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	__super::Update_Rect();
	m_fSpeed = 10.f;

	m_directionX = m_tInfo.fX;
	m_directionY = m_tRect.top;
	m_degree = PI / 180.f;
	m_Radius = m_tInfo.fCX * 0.5f;
}

int CPlayer::Update()
{
	__super::Update_Rect();

	m_directionX = m_tInfo.fX - m_Radius * sin(m_degree * m_degreeCount);
	m_directionY = m_tInfo.fY - m_Radius * cos(m_degree * m_degreeCount);
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
}


void CPlayer::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_directionX, m_directionY);
}

void CPlayer::Release()
{
}

void CPlayer::SetBullet(list<CObj*>* _pBulletList)
{
	m_pBulletCopy = _pBulletList;
}

void CPlayer::SetMonster(list<CObj*>* _pMonsterList)
{
	m_pMonsterCopy = _pMonsterList;
}

CObj* CPlayer::CreateBullet(DIRECTION eDir)
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	//Bullet의 소유권을 갖고 있는 Player의 중심좌표로 설정.
	//FirePosition을 설정
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	//방향에 따른 입력 정보
	pBullet->Set_Dir(eDir);
	pBullet->SetMonster(m_pMonsterCopy);

	return pBullet;
}


void CPlayer::Move(DIRECTION _dir)
{
	switch (_dir)
	{
	case DIR_LEFT:
		++m_degreeCount;
		break;
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;
	case DIR_RIGHT:
		--m_degreeCount;
		break;
	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;
	case DIR_END:
		break;
	default:
		break;
	}
}

void CPlayer::SpawnBullet(DIRECTION _dir)
{
	switch (_dir)
	{
	case DIR_LEFT:
		m_pBulletCopy->push_back(CreateBullet(DIR_LEFT));
		break;
	case DIR_UP:
		m_pBulletCopy->push_back(CreateBullet(DIR_UP));
		break;
	case DIR_RIGHT:
		m_pBulletCopy->push_back(CreateBullet(DIR_RIGHT));
		break;
	case DIR_DOWN:
		m_pBulletCopy->push_back(CreateBullet(DIR_DOWN));
		break;
	case DIR_LUP:
		m_pBulletCopy->push_back(CreateBullet(DIR_LUP));
		break;
	case DIR_RUP:
		m_pBulletCopy->push_back(CreateBullet(DIR_RUP));
		break;
	case DIR_LDOWN:
		m_pBulletCopy->push_back(CreateBullet(DIR_LDOWN));
		break;
	case DIR_RDOWN:
		m_pBulletCopy->push_back(CreateBullet(DIR_RDOWN));
		break;
	case DIR_END:
		break;
	default:
		break;
	}
}

