#include "stdafx.h"
#include "PhysicsSystem.h"

CPhysicsSystem::CPhysicsSystem() : m_pObjCopy(nullptr)
{
}

CPhysicsSystem::~CPhysicsSystem()
{
}

void CPhysicsSystem::Initialize()
{
}

void CPhysicsSystem::Update()
{
}


void CPhysicsSystem::Late_Update()
{
	if (m_pObjCopy == nullptr)
		return;

	//총알 검사
	for (auto bulletIter = (m_pObjCopy)[OBJ_BULLET].begin(); bulletIter != (m_pObjCopy)[OBJ_BULLET].end();)
	{
		bool bBulletDead = false;
		RECT bulletRect = (*bulletIter)->Get_RECT();

		//사각형 검사
		if (bulletRect.left <= (WINCX - WINCX_SMALL) * 0.5 || bulletRect.right >= WINCX - ((WINCX - WINCX_SMALL) * 0.5)
			|| bulletRect.top <= (WINCY - WINCY_SMALL) * 0.5 || bulletRect.bottom >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
		{
			(*bulletIter)->Update_Die();
			bulletIter = (m_pObjCopy)[OBJ_BULLET].erase(bulletIter);
			bBulletDead = true;
		}

		if (!bBulletDead)
		{
			//총알 죽지 않으면 Monster 검사
			for (auto monsterIter = (m_pObjCopy)[OBJ_MONSTER].begin(); monsterIter != (m_pObjCopy)[OBJ_MONSTER].end(); ++monsterIter)
			{
				const RECT* monsterRect = &(*monsterIter)->Get_RECT();
				RECT testRC;
				if (IntersectRect(&testRC, monsterRect, &bulletRect))
				{
					(*monsterIter)->Update_Die();
					(*bulletIter)->Update_Die();
					bulletIter = (m_pObjCopy)[OBJ_BULLET].erase(bulletIter);
					bBulletDead = true;
					break;
				}
			}
		}

		if (!bBulletDead)
			++bulletIter;
	}

	//마우스 검사
	for (auto monsterIter = (m_pObjCopy)[OBJ_MONSTER].begin();monsterIter != (m_pObjCopy)[OBJ_MONSTER].end();)
	{
		RECT testRC;
		const RECT* pRect = &(*monsterIter)->Get_RECT();
		const RECT* mRect = &(m_pObjCopy)[OBJ_MOUSE].front()->Get_RECT();
		if (IntersectRect(&testRC, pRect, mRect))
		{
			(*monsterIter)->Update_Die();
			monsterIter = (m_pObjCopy)[OBJ_MONSTER].erase(monsterIter);
		}
		else
			++monsterIter;
	}
}

void CPhysicsSystem::Release()
{
}

bool CPhysicsSystem::Check_Collision(CObj* _pCObj)
{
	RECT rect = (_pCObj->Get_RECT());

	//충돌조건
	if (rect.left <= (WINCX - WINCX_SMALL) * 0.5 || rect.right >= WINCX - ((WINCX - WINCX_SMALL) * 0.5) || rect.top <= (WINCY - WINCY_SMALL) * 0.5 || rect.bottom >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
		return true;
	else
		return false;
}

bool CPhysicsSystem::Check_Collision(CObj* _pCObj1, CObj* _pCObj2)
{
	INFO info1 = _pCObj1->Get_Info();
	INFO info2 = _pCObj2->Get_Info();

	double distance = sqrt(((info2.fX - info1.fX) * (info2.fX - info1.fX)) + ((info2.fY - info1.fY) * (info2.fY - info1.fY)));

	//충돌조건
	if ((distance <= (info1.fCX * 0.5f) + (info2.fCX * 0.5f)) || (distance <= (info1.fCY * 0.5f) + (info2.fCY * 0.5f)))
		return true;
	else
		return false;
}

void CPhysicsSystem::SetObjList(list<CObj*>* _pList)
{
	m_pObjCopy = _pList;
}



