#include "MainGame.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "WinScreen.h"
#include "Paddle.h"
#include "Brick.h"
#include "Ball.h"
#include "Breakout.h"
#include <iostream>
#include <Windows.h>

bool gameOver = false;
int bricksDestroyed = 0;
void MainGame::Initialize(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("Fonts/visitor1.ttf");
	this->score = new Score(*font, 64U);
	this->lives = new Lives(*font, 64U);
	this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width, 0);

	this->ballVelocity = new sf::Text("Ball Speed: " + std::to_string(difficulty), *font, 32U);
	this->ballVelocity->setFillColor(sf::Color::White);
	this->ballVelocity->setPosition((window->getSize().x - this->lives->getGlobalBounds().width)/ 2 , 0);

	manager = new EntityManager();

	SEManager = new SoundEffectManager;
	SEManager->InitializeSoundEffect();
	
	this->manager->Add("Paddle", new Paddle(window, manager, SEManager));
	this->manager->Add("Ball", new Ball(this->lives, manager, SEManager));
	// Add brick
	MapGenerater();

	this->brickLeft = new sf::Text("Brick Left: " + std::to_string(brickCount), *font, 32U);
	this->brickLeft->setFillColor(sf::Color::White);
	this->brickLeft->setPosition((window->getSize().x - this->lives->getGlobalBounds().width) / 2, 32);
}
void MainGame::Update(sf::RenderWindow* window)
{
	if (bricksDestroyed != 0)
	{
		this->brickCount -= bricksDestroyed;
		this->SEManager->PlaySoundEffect(DestroySound);
		this->score->AddScore();
		bricksDestroyed = 0;
	}
	
	this->brickLeft->setString("Brick Left: " + std::to_string(brickCount));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
	{
		difficulty += .25f;
		levelIndex += 1;
		_currentState.SetState(new WinScreen());
		return;
	}

	if (this->brickCount <= 0)
	{
		gameOver = false;
		difficulty += .25f;
		levelIndex += 1;
		_currentState.SetState(new WinScreen());
		return;
	}

	if (!this->manager->Update(window))
		return;
	this->lives->Update();
	this->score->Update();
	if (gameOver || this->lives->Value() <= 0)
	{
		gameOver = false;
		finalScore = score->value;
		_currentState.SetState(new GameOver());
		return;
	}
}
void MainGame::Render(sf::RenderWindow* window)
{
	this->manager->Render(window);
	window->draw(*this->lives);
	window->draw(*this->score);
	window->draw(*this->ballVelocity);
	window->draw(*this->brickLeft); 
}
void MainGame::Destroy(sf::RenderWindow* window)
{
	delete this->score;
	delete this->lives;
	delete this->font;
	delete this->manager;
	delete this->SEManager;
	delete this->ballVelocity;
	delete this->brickLeft;
}

void MainGame::MapGenerater()
{
	switch (levelIndex % 4)
	{
	case 1:
		this->brickCol = 1;
		this->brickRow = 1;
		break;
	case 2:
		this->brickCol = 16;
		this->brickRow = 6;
		break;
	case 3:
		this->brickCol = 16;
		this->brickRow = 8;
		break;
	case 0:
		this->brickCol = 16;
		this->brickRow = 10;
		break;
	}
	for (int y = 0; y < brickRow; y++)
	{
		if (y == 5)
		{
			for (int x = 0; x < brickCol; x++)
			{
				if (x % 3 == 0)
					this->manager->Add("BrickSet_1", new Brick(x * (64 + 10) + 64, y * (32 + 10) + 64, invincibleBrick));
			}
		}
		else
		{
			for (int x = 0; x < brickCol; x++)
			{
				if (x % 3 == 0 && x != 0)
					this->manager->Add("BrickSet_2", new Brick(x * (64 + 10) + 64, y * (32 + 10) + 64, invisibleBrick));
				else
					this->manager->Add("BrickSet_3", new Brick(x * (64 + 10) + 64, y * (32 + 10) + 64, normalBrick));
				brickCount++;
			}
		}
	}
	for (int i = 0; i < rand()%10 + 1; i++)
	{
		this->manager->Add("MovingBrick_" +i, new Brick(i*64 + 32, 512, movingBrick));
		brickCount++;
	}
}