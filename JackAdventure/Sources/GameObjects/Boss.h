#pragma once
#include "IBoss.h"

class Boss : public IBoss
{
public:
	Boss();
	~Boss();
	void changeNextState(IBState::STATE nextState);

	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();
	BossWeapon* getWeapon();

private:
	void performStateChange();
	HitBox* m_HitBox;
	BossWeapon* m_BossWeapon;


	IBState::STATE m_nextState;

	IBState* m_currentState;
	IBState* m_jumpBiteState;
	IBState* m_jumpState;
	IBState* m_attackState;
};