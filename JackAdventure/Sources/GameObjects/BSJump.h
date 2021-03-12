#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSJump :public IBState {
public:
	BSJump(IBoss* boss);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IBoss* m_Boss;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;

};