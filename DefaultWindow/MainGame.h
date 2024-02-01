#pragma once

#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "System.h"
#include "InputSystem.h"
#include "PhysicsSystem.h"
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Render();
	void		Release();

private:
	HDC			m_DC;
	CObj* m_pPlayer;
	CObj* m_pMonster;
	list<CObj*> m_listBullet;
	CSystem* m_pInputSystem;
	CSystem* m_pPhysicsSystem;
};

