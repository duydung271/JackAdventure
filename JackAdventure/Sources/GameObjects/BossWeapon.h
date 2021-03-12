#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "Bullet.h"

class BossWeapon {
public:
	BossWeapon();
	~BossWeapon();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void Fire(sf::Vector2f startPoint);
private:
	std::list<Bullet*> m_ListBullet;
	int m_Num;
	float m_currentTime;
};