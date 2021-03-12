#include "CreepRino.h"

void CreepRino::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(45, 28));
	m_HitBox->Init(sf::Vector2f(240, 0));
	setStartPoint(sf::Vector2f(screenWidth+100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);

	m_runAni = new Animation(*DATA->getTexture("Rino/Run (52x34)"), sf::Vector2i(6, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Rino/Hit (52x34)"), sf::Vector2i(5, 1), 0.1f);
	//m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
