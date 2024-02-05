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

	//플레이어
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->SetBullet(&m_ObjList[OBJ_BULLET]);

	//몬스터
	for (size_t i = 0; i < 1; i++)
	{
		CObj* monster = CAbstractFactory<CMonster>::Create((i + 1) * 200.f, (i + 1) * 150.f);
		m_ObjList[OBJ_MONSTER].push_back(monster);
		dynamic_cast<CMonster*>(monster)->SetPlayer(m_ObjList[OBJ_PLAYER].front());
	}
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->SetMonster(&m_ObjList[OBJ_MONSTER]);
	//입력시스템
	if (!m_pInputSystem)
		m_pInputSystem = CAbstractFactory<CInputSystem>::Create_System();

	dynamic_cast<CInputSystem*>(m_pInputSystem)->SetPlayer(m_ObjList[OBJ_PLAYER].front());

	//마우스
	m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create());
	dynamic_cast<CMouse*>(m_ObjList[OBJ_MOUSE].front())->SetMonster(&m_ObjList[OBJ_MONSTER]);

	if (!m_pPhysicsSystem)
		m_pPhysicsSystem = CAbstractFactory<CPhysicsSystem>::Create_System();

	dynamic_cast<CPhysicsSystem*>(m_pPhysicsSystem)->SetObjList(m_ObjList);
}

void CMainGame::Update()
{
	m_pInputSystem->Update();

	//일반 Update문을 돌리되, 충돌검사 이후에 해당 OBj가 OBJ_DEAD라면 컨테이너에서 삭제
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
	//	//몬스터
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

	// wsprintf(szBuff, L"Bullet : %d", m_ObjList[OBJ_BULLET].size()); // 모든 서식 문자를 지원하지 않음
	swprintf_s(szBuff, L"총알 : %d", m_ObjList[OBJ_BULLET].size());	// 모든 서식 문자를 지원
	swprintf_s(szBuff2, L"몬스터 : %d", m_ObjList[OBJ_MONSTER].size());	// 모든 서식 문자를 지원

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		20,			// 출력할 윈도우의 x,y 위치를 전달
		20,
		szBuff,		// 출력할 문자열의 시작 주소
		lstrlen(szBuff)); // 문자열의 순수 길이

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		20,			// 출력할 윈도우의 x,y 위치를 전달
		40,
		szBuff2,		// 출력할 문자열의 시작 주소
		lstrlen(szBuff2)); // 문자열의 순수 길이

	//RECT rc{ 50, 50, 200, 200 };

	//DrawText(m_hDC, // 문자열을 복사할 화면 dc
	//		szBuff,// 출력할 문자열의 시작 주소
	//		lstrlen(szBuff), // 문자열의 순수 길이
	//		&rc,	// 문자를 출력할 렉트 정보
	//		DT_CENTER);	// 정렬 기준
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
