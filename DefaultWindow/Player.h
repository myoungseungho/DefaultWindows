#pragma once
#include "Obj.h"
#include "Bullet.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
public:
	CObj* CreateBullet(DIRECTION);

	void SetBullet(list<CObj*>*);
	void SetMonster(list<CObj*>*);
	void Move(DIRECTION);
	void SpawnBullet(DIRECTION);

private:
	list<CObj*>* m_pBulletCopy;
	list<CObj*>* m_pMonsterCopy;

	long m_directionX;
	long m_directionY;
	float m_Radius;
	float m_degree;
	int m_degreeCount;
};

