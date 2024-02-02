#pragma once
#include "System.h"
#include "Player.h"
#include "Obj.h"
class CInputSystem : public CSystem
{
public:
	CInputSystem();
	virtual ~CInputSystem();
public:
	void Initialize() override;
	void Update() override;
	void Release() override;
public:
	void SetPlayer(CObj*);
private:
	void PlayerUpdate();
private:
	CObj* m_pPlayerCopy;

	// CSystem��(��) ���� ��ӵ�
	void Late_Update() override;
};

