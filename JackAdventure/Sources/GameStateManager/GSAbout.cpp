#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);
}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}
