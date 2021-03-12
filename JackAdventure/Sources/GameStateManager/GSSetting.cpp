#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth -screenWidth/20, screenHeight/8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);
	//turn on music
	button = new GameButton();
	button->Init("misic");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->setAllowSound(true); });
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("music_off");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {DATA->setAllowSound(false); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("SETTINGS");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth/2,screenHeight/5);
}

void GSSetting::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
