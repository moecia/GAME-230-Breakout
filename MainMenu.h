#pragma once
#include "GameState.h"
#include "Breakout.h"
class MainMenu : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* usingKeyboard;
	sf::Text* usingMouse;
	sf::Text* quit;

	int selected;

	bool upKey, downKey;
};
extern int gameMode;