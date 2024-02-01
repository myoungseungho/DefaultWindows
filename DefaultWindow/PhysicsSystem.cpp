#include "stdafx.h"
#include "PhysicsSystem.h"

CPhysicsSystem::CPhysicsSystem()
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
