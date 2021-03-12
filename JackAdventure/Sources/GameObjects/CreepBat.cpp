#include "CreepBat.h"

void CreepBat::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(35, 25));
	m_HitBox->Init(sf::Vector2f(300, 0));
	setStartPoint(sf::Vector2f(screenWidth, groundY - 200));
	m_HitBox->setPosition(screenWidth, groundY-200);

	m_runAni = new Animation(*DATA->getTexture("Bat/Flying (46x30)"), sf::Vector2i(7, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Bat/Hit (46x30)"), sf::Vector2i(5, 1), 0.1f);
	m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
