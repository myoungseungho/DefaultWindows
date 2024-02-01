#pragma once
#include "System.h"

class CPhysicsSystem : public CSystem
{
public:

	void Initialize() override;
	void Update() override;
	void Release() override;
};

