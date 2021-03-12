#pragma once
#include "IBState.h"
#include "HitBox.h"

class IBoss
{
public:
	virtual void changeNextState(IBState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual BossWeapon* getWeapon()=0;
};