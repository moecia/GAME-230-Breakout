#pragma once

#include "EntityManager.h"
#include "GameState.h"
#include "Lives.h"
#include "Score.h"
#include "SoundEffectManager.h"
extern int bricksDestroyed;
extern bool gameOver;

class MainGame : public State
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void MapGenerater();
private:
	SoundEffectManager *SEManager;
	Lives* lives;
	Score* score;
	sf::Font* font;
	sf::Text* ballVelocity;
	sf::Text* brickLeft;
	EntityManager* manager;
	int brickCol;
	int brickRow;
	int brickCount;
};
extern int finalScore;