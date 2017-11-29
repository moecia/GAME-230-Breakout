#include "WinScreen.h"
#include "MainGame.h"

void WinScreen::Initialize(sf::RenderWindow* window)
{
	enterKey = false;
	sf::Font* font = new sf::Font();
	font->loadFromFile("Fonts/visitor1.ttf");
	this->winText = new sf::Text("You Win! Press Enter to next level.", *font, 32U);
	this->winText->setFillColor(sf::Color::White);
	this->winText->setOrigin(sf::Vector2f(this->winText->getGlobalBounds().width / 2, this->winText->getGlobalBounds().height / 2));
	this->winText->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));

	this->SEManager = new SoundEffectManager;
	this->SEManager->InitializeSoundEffect();
	this->SEManager->PlaySoundEffect(DestroySound);
	this->SEManager->PlaySoundEffect(WinSound);
}
void WinScreen::Update(sf::RenderWindow* window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey)
	{
		_currentState.SetState(new MainGame());
	}
	enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void WinScreen::Render(sf::RenderWindow* window)
{
	window->draw(*this->winText);
}
void WinScreen::Destroy(sf::RenderWindow* window)
{
	delete this->winText;
	delete this->SEManager;
}
