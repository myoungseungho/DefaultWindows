#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr), m_DC(NULL)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	dynamic_cast<CPlayer*>(m_pPlayer)->SetBullet(&m_listBullet);
}

void CMainGame::Update()
{
	m_pPlayer->Update();

	for (auto iter = m_listBullet.begin();iter != m_listBullet.end();)
	{
		//�Ѿ� Update
		(*iter)->Update();
		
		//�浹 üũ
		Collision(iter);
	}
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, (WINCX - WINCX_SMALL) * 0.5, (WINCY - WINCY_SMALL) * 0.5, WINCX - ((WINCX - WINCX_SMALL) * 0.5), WINCY - ((WINCY - WINCY_SMALL) * 0.5));

	m_pPlayer->Render(m_DC);

	for (auto& iter : m_listBullet)
	{
		iter->Render(m_DC);
	}
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);
	ReleaseDC(g_hWnd, m_DC);
}

void CMainGame::Collision(list<CObj*>::iterator& iter)
{
	INFO info = (*iter)->Get_Info();
	float fLeftX = info.fX - (info.fCX * 0.5f);
	float fUpY = info.fY - (info.fCY * 0.5f);
	float fRightX = info.fX + (info.fCX * 0.5f);
	float fDownY = info.fY + (info.fCY * 0.5f);

	//�浹����
	if (fLeftX <= (WINCX - WINCX_SMALL) * 0.5 || fRightX >= WINCX - ((WINCX - WINCX_SMALL) * 0.5) || fUpY <= (WINCY - WINCY_SMALL) * 0.5 || fDownY >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
	{
		Safe_Delete(*iter);
		iter = m_listBullet.erase(iter);
	}
	else
	{
		++iter;
	}
}

