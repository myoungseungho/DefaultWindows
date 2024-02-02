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
	void Late_Update() override;
	void Release() override;
public:
	void SetObjList(list<CObj*>*);
private:
	list<CObj*>* m_pObjCopy;
};

