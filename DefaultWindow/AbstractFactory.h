#pragma once
#include "Obj.h"
#include "System.h"
template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj* Create()
	{
		CObj* obj = new T;
		obj->Initialize();
		return obj;
	}

	static CSystem* Create_System()
	{
		CSystem* system = new T;
		system->Initialize();
		return system;
	}

	static CObj* Create(float _fX, float _fY)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}
};