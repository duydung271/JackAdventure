#include "BSJumpBite.h"

BSJumpBite::BSJumpBite(IBoss* boss)
{
	m_Boss = boss;
}

void BSJumpBite::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Boss1/jump-cycle-bite-attack"), sf::Vector2i(6, 3), 0.1f, 17);
	m_ChangeTime = 1.f;
	m_currentTime = 0.f;
}

void BSJumpBite::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation2* ani = (Animation2*)m_Animation;
	if (m_currentTime > m_ChangeTime && (ani->getCurrentFrameCount() == ani->getFrameTotals() - 1)) {
		int luckyState = rand() % 2;
		switch (luckyState)
		{
		case 0:
			m_Boss->changeNextState(STATE::ATTACK);
			break;
		case 1:
			m_Boss->changeNextState(STATE::JUMP);
			break;
		default:
			break;
		}
	}
	if (m_Boss->getHitBox()->getPosition().x < 300) {
		m_Boss->getHitBox()->move(200 * deltaTime, 0);
	}
	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void BSJumpBite::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSJumpBite::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
