#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();
public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

