#include "BSAttack.h"

BSAttack::BSAttack(IBoss* boss)
{
	m_Boss = boss;
}

void BSAttack::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Boss1/poison-attack"), sf::Vector2i(6, 3), 0.1f,17);
}

void BSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	//printf("%d\n", ani->getCurrentFrameCount());
	if (ani->getCurrentFrameCount() == ani->getFrameTotals() - 1) {
		sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
		pos.y += 60;
		m_Boss->getWeapon()->Fire(pos);
		m_Boss->changeNextState(STATE::JUMP_BITE);
	}
	if (m_Boss->getHitBox()->getPosition().x>-100) {
		m_Boss->getHitBox()->move(-100 * deltaTime, 0);
	}

	sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
	pos.y += 27;
	m_Animation->setPosition(pos);
}

void BSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSAttack::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
