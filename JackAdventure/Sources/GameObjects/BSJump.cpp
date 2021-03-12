#include "BSJump.h"

BSJump::BSJump(IBoss* boss)
{
	m_Boss = boss;
}

void BSJump::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Boss1/jump-cycle"), sf::Vector2i(6, 3), 0.1f,17);
	m_ChangeTime = 3.f;
	m_currentTime = 0.f;
}

void BSJump::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation2* ani = (Animation2*)m_Animation;
	if (m_currentTime > m_ChangeTime&&(ani->getCurrentFrameCount()==ani->getFrameTotals()-1)) {
		int luckyState = rand() % 2;
		switch (luckyState)
		{
		case 0:
			m_Boss->changeNextState(STATE::ATTACK);
			break;
		case 1:
			m_Boss->changeNextState(STATE::JUMP_BITE);
			break;
		default:
			break;
		}
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void BSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSJump::Reset()
{	m_Animation->Reset();
	m_currentTime = 0.f;
}
