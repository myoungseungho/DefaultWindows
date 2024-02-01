#pragma once
#include "System.h"
class CInputSystem : public CSystem
{
public:
	void Initialize() override;
	void Update() override;
	void Release() override;
};

