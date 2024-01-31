#pragma once
#include "Obj.h"
class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();
public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void TransitionState();
private:
	MONSTERSTATE m_State;
};

