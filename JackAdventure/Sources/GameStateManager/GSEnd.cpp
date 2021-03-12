#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState(); 
		GSM->PopState(); 
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
	});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("END GAME!");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);

	//Best Score
	m_bestScore.setString("BEST SOCRE: "+std::to_string(ScoreManager::GetInstance()->getBestScore()));
	m_bestScore.setFont(*DATA->getFont("ARCADE"));
	m_bestScore.setPosition(screenWidth / 2, screenHeight / 2);

	//current Score
	m_currentScore.setString("YOUR SOCRE: " + std::to_string(ScoreManager::GetInstance()->getCurrentScore()));
	m_currentScore.setFont(*DATA->getFont("ARCADE"));
	m_currentScore.setPosition(screenWidth / 2, screenHeight / 2 + 50);
}

void GSEnd::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}
