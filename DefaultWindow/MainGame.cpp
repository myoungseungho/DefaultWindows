#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr), m_DC(NULL), m_pMonster(nullptr), m_pInputSystem(nullptr), m_pPhysicsSystem(nullptr)
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

	if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}

	dynamic_cast<CPlayer*>(m_pPlayer)->SetBullet(&m_listBullet);

	if (!m_pInputSystem)
	{
		m_pInputSystem = new CInputSystem;
		m_pInputSystem->Initialize();
	}

	dynamic_cast<CInputSystem*>(m_pInputSystem)->SetPlayer(m_pPlayer);

	if (!m_pPhysicsSystem)
	{
		m_pPhysicsSystem = new CPhysicsSystem;
		m_pPhysicsSystem->Initialize();
	}
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	m_pMonster->Update();
	m_pInputSystem->Update();

	for (auto iter = m_listBullet.begin();iter != m_listBullet.end();)
	{
		//�Ѿ� Update
		(*iter)->Update();

		//�浹 üũ
		bool isCollision = dynamic_cast<CPhysicsSystem*>(m_pPhysicsSystem)->Collision(*iter);
		if (isCollision)
		{
			Safe_Delete(*iter);
			iter = m_listBullet.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	bool isMonsterCollision = dynamic_cast<CPhysicsSystem*>(m_pPhysicsSystem)->Collision(m_pMonster);
	if (isMonsterCollision)
		dynamic_cast<CMonster*>(m_pMonster)->TransitionState();
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, (WINCX - WINCX_SMALL) * 0.5, (WINCY - WINCY_SMALL) * 0.5, WINCX - ((WINCX - WINCX_SMALL) * 0.5), WINCY - ((WINCY - WINCY_SMALL) * 0.5));

	m_pPlayer->Render(m_DC);
	m_pMonster->Render(m_DC);

	for (auto& iter : m_listBullet)
	{
		iter->Render(m_DC);
	}
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);
	Safe_Delete<CObj*>(m_pMonster);
	Safe_Delete<CSystem*>(m_pInputSystem);
	Safe_Delete<CSystem*>(m_pPhysicsSystem);
	ReleaseDC(g_hWnd, m_DC);
}
