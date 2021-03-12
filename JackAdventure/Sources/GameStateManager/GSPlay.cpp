#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	printf("Play game");
	m_Background.Init();
	m_Player.Init();
	m_Boss.Init(m_CollisionManager);
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_CreepManager.Init(m_CollisionManager);

	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(50,50);

	DATA->playMusic("Uprising");
	DATA->getMusic("Uprising")->setLoop(true);;
	DATA->getMusic("Uprising")->setVolume(30);
}

void GSPlay::Update(float deltaTime)
{
	if (m_Player.getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f) {
			m_currentScore++;
			m_Score.setString(std::to_string(m_currentScore));
			m_currentTime -= 1.f;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);

	if (m_Player.getHitBox()->isAlive()) m_Background.Update(deltaTime);
	m_Player.Update(deltaTime);
	if (m_Player.getHitBox()->isAlive()) {
		m_Boss.Update(deltaTime);
		m_CreepManager.Update(deltaTime);
		m_CollisionManager.Update();
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	m_Boss.Render(window);
	m_Player.Render(window);
	m_CreepManager.Render(window);
	window->draw(m_Score);

}
