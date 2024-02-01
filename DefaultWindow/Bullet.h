#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

