#pragma once
#include "Player.h"
class CPlayerSatellite : public CObj
{
public:
	CPlayerSatellite();
	~CPlayerSatellite();
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void SetPlayer(CObj*);
private:
	float m_fBigRadius;
	float m_fSmallRadius;
	float m_fDegree;
	int m_degreeCount;
	float m_directionX;
	float m_directionY;

	CObj* m_pPlayerCopy;
};
