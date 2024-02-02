#include "stdafx.h"
#include "PhysicsSystem.h"
#include "CollisionMgr.h"

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

	CCollisionMgr::Collision_Rect(m_pObjCopy[OBJ_BULLET], m_pObjCopy[OBJ_MONSTER]);
	CCollisionMgr::Collision_Rect(m_pObjCopy[OBJ_MOUSE], m_pObjCopy[OBJ_MONSTER]);
}

void CPhysicsSystem::Release()
{
}

void CPhysicsSystem::SetObjList(list<CObj*>* _pList)
{
	m_pObjCopy = _pList;
}



