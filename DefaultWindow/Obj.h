#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_RECT() { return m_tRect; }
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_Dir(DIRECTION eDir) { m_eDir = eDir; }


public:
	virtual void Initialize()		PURE;
	virtual int  Update()			PURE;
	virtual void Late_Update()		PURE;
	virtual void Render(HDC hDC)	PURE;
	virtual void Release()			PURE;
public:
	void        Update_Die();
protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION   m_eDir;

	float m_fSpeed;
	bool m_bDead;
};

