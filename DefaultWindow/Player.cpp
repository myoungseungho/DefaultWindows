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

	Key_Input();

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

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tInfo.fY += m_fSpeed;


	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pBullet->push_back(CreateBullet(DIR_LEFT));
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pBullet->push_back(CreateBullet(DIR_UP));
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pBullet->push_back(CreateBullet(DIR_RIGHT));
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_pBullet->push_back(CreateBullet(DIR_DOWN));
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_pBullet->push_back(CreateBullet(DIR_LUP));
		m_pBullet->push_back(CreateBullet(DIR_RUP));
		m_pBullet->push_back(CreateBullet(DIR_LDOWN));
		m_pBullet->push_back(CreateBullet(DIR_RDOWN));
	}

}
