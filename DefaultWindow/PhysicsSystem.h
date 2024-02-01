#pragma once
#include "System.h"
#include "Obj.h"
class CPhysicsSystem : public CSystem
{
public:
	CPhysicsSystem();
	virtual ~CPhysicsSystem();
public:
	void Initialize() override;
	void Update() override;
	void Release() override;
public:
	bool Check_Collision(CObj* _pCObj);
	bool Check_Collision(CObj* _pCObj1, CObj* _pCObj2);
};

