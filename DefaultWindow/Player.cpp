#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer() :m_pBullet(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
}

void CPlayer::Update()
{
	__super::Update_Rect();
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::SetBullet(list<CObj*>* _pBulletList)
{
	m_pBullet = _pBulletList;
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

	return pBullet;
}


void CPlayer::Move(DIRECTION _dir)
{
	switch (_dir)
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
		m_pBullet->push_back(CreateBullet(DIR_LEFT));
		break;
	case DIR_UP:
		m_pBullet->push_back(CreateBullet(DIR_UP));
		break;
	case DIR_RIGHT:
		m_pBullet->push_back(CreateBullet(DIR_RIGHT));
		break;
	case DIR_DOWN:
		m_pBullet->push_back(CreateBullet(DIR_DOWN));
		break;
	case DIR_LUP:
		m_pBullet->push_back(CreateBullet(DIR_LUP));
		break;
	case DIR_RUP:
		m_pBullet->push_back(CreateBullet(DIR_RUP));
		break;
	case DIR_LDOWN:
		m_pBullet->push_back(CreateBullet(DIR_LDOWN));
		break;
	case DIR_RDOWN:
		m_pBullet->push_back(CreateBullet(DIR_RDOWN));
		break;
	case DIR_END:
		break;
	default:
		break;
	}
}
