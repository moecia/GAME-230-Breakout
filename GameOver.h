#pragma once
#include "GameState.h"
#include "Score.h" 
class GameOver : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Text* gameOverText;
	bool enterKey;
};
