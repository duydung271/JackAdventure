#include "PSFall.h"

PSFall::PSFall(IPlayer* player)
{
	m_Player = player;
}

void PSFall::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Fall"), sf::Vector2i(2, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSFall::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	float v = 10 * m_currentTime;
	m_Player->getHitBox()->move(0, v);
	if (m_Player->getHitBox()->getPosition().y >= groundY) {
		if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);
		else m_Player->changeNextState(RUN);
		m_currentTime = 0.f;
	}

	if (m_Player->getHitBox()->isAlive()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFall::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
