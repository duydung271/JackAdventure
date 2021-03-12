#include "Boss.h"
#include "BSAttack.h"
#include "BSJump.h"
#include "BSJumpBite.h"

Boss::Boss()
{
	m_nextState = IBState::SNULL;
	m_jumpBiteState = new BSJumpBite(this);
	m_jumpState = new BSJump(this);
	m_attackState = new BSAttack(this);
	m_currentState = m_jumpState;
	m_BossWeapon = new BossWeapon();
}

Boss::~Boss()
{
	if (m_jumpBiteState != nullptr) {
		delete m_jumpBiteState;
	}
	if (m_jumpState != nullptr) {
		delete m_jumpState;
	}
	if (m_attackState != nullptr) {
		delete m_attackState;
	}
	if (m_BossWeapon != nullptr) {
		delete m_BossWeapon;
	}
	m_currentState = nullptr;

}

void Boss::changeNextState(IBState::STATE nextState)
{
	m_nextState = nextState;
}

void Boss::Init(CollisionManager& collisionManager)
{
	m_jumpBiteState->Init();
	m_jumpState->Init();
	m_attackState->Init();

	m_HitBox = new HitBox(sf::Vector2i(304-100, 246-50));
	m_HitBox->setPosition(100, groundY-(m_HitBox->getSize().y)/2+20);
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_HitBox->SetTag(BOSS);

	collisionManager.addObj(m_HitBox);
	m_BossWeapon->Init(collisionManager);
}

void Boss::Update(float deltaTime)
{
	performStateChange();
	m_BossWeapon->Update(deltaTime);
	m_currentState->Update(deltaTime);
	
}

void Boss::Render(sf::RenderWindow* window)
{
	m_BossWeapon->Render(window);
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
	
}

HitBox* Boss::getHitBox()
{
	return m_HitBox;
}

BossWeapon* Boss::getWeapon()
{
	return m_BossWeapon;
}

void Boss::performStateChange()
{
	if (m_nextState != IBState::SNULL) {
		switch (m_nextState)
		{
		case IBState::JUMP_BITE:
			m_currentState = m_jumpBiteState;
			break;
		case IBState::JUMP:
			m_currentState = m_jumpState;
			break;
		case IBState::ATTACK:
			m_currentState = m_attackState;
			break;
		default:
			break;
		}
		m_nextState = IBState::SNULL;
		m_currentState->Reset();
	}
}
