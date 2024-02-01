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

bool CPhysicsSystem::Collision(CObj* _pCObj)
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
