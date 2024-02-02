#pragma once
#include "stdafx.h"
#include "Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();
public:
	static void Collision_Rect(list<CObj*>, list<CObj*>);
	static void Collision_Sphere(list<CObj*>, list<CObj*>);
private:
	static bool Check_Sphere(CObj* pDst, CObj* pSrc);
};

