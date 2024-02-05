#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
	: m_DC(NULL), m_pInputSystem(nullptr), m_pPhysicsSystem(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	//�÷��̾�
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->SetBullet(&m_ObjList[OBJ_BULLET]);

	//����
	for (size_t i = 0; i < 1; i++)
	{
		CObj* monster = CAbstractFactory<CMonster>::Create((i + 1) * 200.f, (i + 1) * 150.f);
		m_ObjList[OBJ_MONSTER].push_back(monster);
		dynamic_cast<CMonster*>(monster)->SetPlayer(m_ObjList[OBJ_PLAYER].front());
	}
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->SetMonster(&m_ObjList[OBJ_MONSTER]);
	//�Է½ý���
	if (!m_pInputSystem)
		m_pInputSystem = CAbstractFactory<CInputSystem>::Create_System();

	dynamic_cast<CInputSystem*>(m_pInputSystem)->SetPlayer(m_ObjList[OBJ_PLAYER].front());

	//���콺
	m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create());
	dynamic_cast<CMouse*>(m_ObjList[OBJ_MOUSE].front())->SetMonster(&m_ObjList[OBJ_MONSTER]);

	if (!m_pPhysicsSystem)
		m_pPhysicsSystem = CAbstractFactory<CPhysicsSystem>::Create_System();

	dynamic_cast<CPhysicsSystem*>(m_pPhysicsSystem)->SetObjList(m_ObjList);
}

void CMainGame::Update()
{
	m_pInputSystem->Update();

	//�Ϲ� Update���� ������, �浹�˻� ���Ŀ� �ش� OBj�� OBJ_DEAD��� �����̳ʿ��� ����
	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();
			if (iResult == OBJ_DEAD)
			{
				Safe_Delete((*iter));
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	//if (m_ObjList[OBJ_MONSTER].size() == 0)
	//{
	//	//����
	//	for (size_t i = 0; i < 3; i++)
	//	{
	//		m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create((i + 1) * 200.f, (i + 1) * 150.f));
	//	}
	//	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->SetMonster(&m_ObjList[OBJ_MONSTER]);
	//}
}

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}

	m_pPhysicsSystem->Late_Update();
}

void CMainGame::Render()
{
	++m_iFPS;

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	Rectangle(m_DC, (WINCX - WINCX_SMALL) * 0.5, (WINCY - WINCY_SMALL) * 0.5, WINCX - ((WINCX - WINCX_SMALL) * 0.5), WINCY - ((WINCY - WINCY_SMALL) * 0.5));

	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for (auto iter : m_ObjList[i])
		{
			iter->Render(m_DC);
		}
	}

	TCHAR	szBuff[32] = L"";
	TCHAR	szBuff2[32] = L"";

	// wsprintf(szBuff, L"Bullet : %d", m_ObjList[OBJ_BULLET].size()); // ��� ���� ���ڸ� �������� ����
	swprintf_s(szBuff, L"�Ѿ� : %d", m_ObjList[OBJ_BULLET].size());	// ��� ���� ���ڸ� ����
	swprintf_s(szBuff2, L"���� : %d", m_ObjList[OBJ_MONSTER].size());	// ��� ���� ���ڸ� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		20,			// ����� �������� x,y ��ġ�� ����
		20,
		szBuff,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuff)); // ���ڿ��� ���� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		20,			// ����� �������� x,y ��ġ�� ����
		40,
		szBuff2,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuff2)); // ���ڿ��� ���� ����

	//RECT rc{ 50, 50, 200, 200 };

	//DrawText(m_hDC, // ���ڿ��� ������ ȭ�� dc
	//		szBuff,// ����� ���ڿ��� ���� �ּ�
	//		lstrlen(szBuff), // ���ڿ��� ���� ����
	//		&rc,	// ���ڸ� ����� ��Ʈ ����
	//		DT_CENTER);	// ���� ����
}

void CMainGame::Release()
{
	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
	}

	Safe_Delete<CSystem*>(m_pInputSystem);
	Safe_Delete<CSystem*>(m_pPhysicsSystem);
	ReleaseDC(g_hWnd, m_DC);
}
