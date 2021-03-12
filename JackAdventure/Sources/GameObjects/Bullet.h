#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Bullet {
public:
	Bullet();
	~Bullet();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(sf::Vector2f point) { m_startPoint = point; }

	void Reset();
	bool isStop() { return m_stop; }
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;

	bool m_stop;
	bool m_soundIsPlaying;
};