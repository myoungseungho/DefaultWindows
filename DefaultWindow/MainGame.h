#pragma once

#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "System.h"
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include "AbstractFactory.h"
#include "Mouse.h"
#include "CollisionMgr.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_DC;
	CSystem* m_pInputSystem;
	CSystem* m_pPhysicsSystem;
	list<CObj*> m_ObjList[OBJ_END];

	DWORD			m_dwTime;
	TCHAR			m_szFPS[16];
	int				m_iFPS;
};

