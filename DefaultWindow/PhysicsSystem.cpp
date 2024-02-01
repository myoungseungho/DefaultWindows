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
	INFO info = _pCObj->Get_Info();
	float fLeftX = info.fX - (info.fCX * 0.5f);
	float fUpY = info.fY - (info.fCY * 0.5f);
	float fRightX = info.fX + (info.fCX * 0.5f);
	float fDownY = info.fY + (info.fCY * 0.5f);

	//충돌조건
	if (fLeftX <= (WINCX - WINCX_SMALL) * 0.5 || fRightX >= WINCX - ((WINCX - WINCX_SMALL) * 0.5) || fUpY <= (WINCY - WINCY_SMALL) * 0.5 || fDownY >= WINCY - ((WINCY - WINCY_SMALL) * 0.5))
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
	if ((distance <= (info1.fCX * 0.5f) + (info2.fCX * 0.5f))||(distance<= (info1.fCY * 0.5f) + (info2.fCY * 0.5f)))
		return true;
	else
		return false;
}
