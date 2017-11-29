#include "GameOver.h"
#include "MainMenu.h"
#include "MainGame.h"
int finalScore;
void GameOver::Initialize(sf::RenderWindow* window)
{
	enterKey = false;
	sf::Font* font = new sf::Font();	
	font->loadFromFile("Fonts/visitor1.ttf");

	this->gameOverText = new sf::Text("Game Over! you final score is: " + std::to_string(finalScore) +"\n    Press Enter to menu.", *font, 32U);
	this->gameOverText->setFillColor(sf::Color::Red);
	this->gameOverText->setOrigin(sf::Vector2f(this->gameOverText->getGlobalBounds().width / 2, this->gameOverText->getGlobalBounds().height / 2));
	this->gameOverText->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));


	this->SEManager = new SoundEffectManager;
	this->SEManager->InitializeSoundEffect();
	this->SEManager->PlaySoundEffect(LoseLifeSound);
	this->SEManager->PlaySoundEffect(LoseLifeSound);
}
void GameOver::Update(sf::RenderWindow* window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey)
	{
		_currentState.SetState(new MainMenu());
	}
	enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void GameOver::Render(sf::RenderWindow* window)
{

	window->draw(*this->gameOverText);
}
void GameOver::Destroy(sf::RenderWindow* window)
{
	delete this->gameOverText;
	delete this->SEManager;
}
