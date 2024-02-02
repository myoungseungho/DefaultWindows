#pragma once
#include "stdafx.h"
#include "Define.h"
class CSystem
{
public:
	CSystem();
	virtual ~CSystem();
public:

	virtual void Initialize()		PURE;
	virtual void Update()			PURE;
	virtual void Late_Update()		PURE;
	virtual void Release()			PURE;
};

