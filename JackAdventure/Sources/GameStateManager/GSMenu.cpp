#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, screenHeight / 2+screenHeight/10);
	button->setSize(sf::Vector2f(150,150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2+screenWidth/4, screenHeight-screenHeight/8);
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("settings");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	m_ListBtn.push_back(button);

	//about Button
	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("prize");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y/2);

	ScoreManager::GetInstance()->readFile();
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
