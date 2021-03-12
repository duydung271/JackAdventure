#pragma once
#include "GameStateBase.h"
class GSAbout : public GameStateBase {
public:
	GSAbout();
	virtual ~GSAbout();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;

};