#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_CreepNum = 10;
	m_TimeSpwanCreep = 2.f;
	m_currentTime = 0.f;
	//rand() % (max – min + 1) + min
}

CreepManager::~CreepManager()
{
	for (auto it : m_ListCreepRino) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepRino.clear();

	for (auto it : m_ListCreepBat) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepBat.clear();
}

void CreepManager::Init(CollisionManager &collisionManager)
{
	
	for (int i = 0; i < m_CreepNum; i++) {
		CreepRino* creepR = new CreepRino();
		creepR->Init();
		creepR->getHitBox()->setAlive(false);
		m_ListCreepRino.push_back(creepR);
		collisionManager.addObj(creepR->getHitBox());

		CreepBat* creepB = new CreepBat();
		creepB->Init();
		creepB->getHitBox()->setAlive(false);
		m_ListCreepBat.push_back(creepB);
		collisionManager.addObj(creepB->getHitBox());
		
	}
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_TimeSpwanCreep) {
		SpawnRino();
		SpawnBat();
		m_currentTime = 0.f;
	}
	for (auto creep : m_ListCreepRino) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_ListCreepBat) {
		creep->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for (auto creep : m_ListCreepRino) {
		creep->Render(window);
	}
	for (auto creep : m_ListCreepBat) {
		creep->Render(window);
	}
}

void CreepManager::SpawnRino()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepRino) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand()%(150-50+1)+50, groundY));
	creep->getHitBox()->setVelocity(sf::Vector2f(200+rand()%100,0));
	creep->Reset();
}

void CreepManager::SpawnBat()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepBat) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY-(rand()%(300 - 100 + 1) + 100)));
	creep->Reset();
}
