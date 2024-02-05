#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet(BULLETMODE = BULLET_NORMAL);
	virtual ~CBullet();
public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void SetMonster(list<CObj*>*);
	void SetDestination(float, float);
private:
	list<CObj*>* m_pMonsterCopy;

	float m_PlayerX;
	float m_PlayerY;
	float m_FirePositionX;
	float m_FirePositionY;
	float m_fDegree;
	float m_fSmallRadius;
	long m_directionX;
	long m_directionY;
	int m_degreeCount;

	BULLETMODE m_BulletMode;
};

