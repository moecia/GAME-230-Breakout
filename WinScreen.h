#pragma once
#include "GameState.h"
#include "SoundEffectManager.h"
class WinScreen : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Text* winText;
	bool enterKey;
	SoundEffectManager *SEManager;
};
