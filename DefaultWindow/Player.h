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
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
public:
	void SetBullet(list<CObj*>*);
	CObj* CreateBullet(DIRECTION);
	void Move(DIRECTION);
	void SpawnBullet(DIRECTION);

private:
	list<CObj*>* m_pBullet;

};

