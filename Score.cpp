#include "Score.h"
int score;
Score::Score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size)
{
	this->value = score;
}

void Score::AddScore()
{
	score += 1;
	this->value = score;
}

void Score::Update()
{
	this->setString("Score: " + std::to_string(score));
}