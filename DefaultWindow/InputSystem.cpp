#include "stdafx.h"
#include "InputSystem.h"

CInputSystem::CInputSystem() : m_pPlayerCopy(nullptr)
{

}

CInputSystem::~CInputSystem()
{
}

void CInputSystem::Initialize()
{
}

void CInputSystem::Update()
{
	PlayerUpdate();
}

void CInputSystem::Release()
{
}

void CInputSystem::SetPlayer(CObj* _pPlayer)
{
	m_pPlayerCopy = _pPlayer;
}

void CInputSystem::PlayerUpdate()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->Move(DIR_RIGHT);

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->Move(DIR_LEFT);

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->Move(DIR_UP);

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->Move(DIR_DOWN);

	if (GetAsyncKeyState('A') & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_LEFT);
	if (GetAsyncKeyState('W') & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_UP);
	if (GetAsyncKeyState('D') & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_RIGHT);
	if (GetAsyncKeyState('S') & 0x8000)
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_DOWN);

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_LUP);
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_RUP);
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_LDOWN);
		dynamic_cast<CPlayer*>(m_pPlayerCopy)->SpawnBullet(DIR_RDOWN);
	}
}
