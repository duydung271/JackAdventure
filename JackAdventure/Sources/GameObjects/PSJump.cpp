#include "PSJump.h"

PSJump::PSJump(IPlayer* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}

void PSJump::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Jump"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSJump::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;

	float v = 10 * m_currentTime;
	if (-m_Player->getHitBox()->getVelocity().y * deltaTime + v >= 0) {
		m_Player->changeNextState(FALL);
		m_currentTime = 0.f;
	}
	else m_Player->getHitBox()->move(0, -m_Player->getHitBox()->getVelocity().y * deltaTime+v);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::FALL);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSJump::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
