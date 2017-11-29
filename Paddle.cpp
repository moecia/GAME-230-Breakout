#include "MainGame.h"
#include "MainMenu.h"
#include "Paddle.h"
#include "Ball.h"
#include <math.h>
#include <iostream>
Paddle::Paddle(sf::RenderWindow* window, EntityManager* gameObjManager, SoundEffectManager* SEManager)
{
	this->Load("Paddle.png");
	this->setScale(0.5f, 0.35f);
	this->setPosition(window->getSize().x / 2 - this->getGlobalBounds().width / 2, window->getSize().y - this->getGlobalBounds().height);
	this->groupId = 1;
	this->gameObjManager = gameObjManager;
	this->SEManager = SEManager;
	Entity::scroll = sf::Vector2f(0, 0);
}

bool Paddle::Update(sf::RenderWindow* window)
{
	switch (gameMode)
	{
	case 0:
		this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) * this->velocityPaddle_keyboard;
		break;
	case 1:
		if (sf::Mouse::getPosition(*window).x > this->getPosition().x + this->getGlobalBounds().width / 2)
			this->move(velocityPaddle_mouse, 0);
		else if (sf::Mouse::getPosition(*window).x < this->getPosition().x + this->getGlobalBounds().width / 2)
			this->move(-velocityPaddle_mouse, 0);
		else
			this->move(0, 0);
		break;
	}

	if (this->velocity.x > 0)
	{
		this->direction = 0.0f;
	}
	else if (this->velocity.x < 0)
	{
		this->direction = 180.0f;
	}
	while (this->getPosition().x <= 0)
	{
		this->move(1, 0);
		this->velocity.x = 0;
	}
	while (this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
	{
		this->move(-1, 0);
		this->velocity.x = 0;
	}

	Entity::Update(window);
	return true;
}

void Paddle::Collision(Entity* entity)
{
	switch (entity->GroupID())
	{
	case 3:
		SEManager->PlaySoundEffect(PaddleSound);
		if (this->getPosition().x + 1.5f * entity->getGlobalBounds().width > entity->getPosition().x)
			reinterpret_cast<Ball*>(entity)->BouncePannel(-abs(entity->getPosition().x - (this->getPosition().x + 1.5f * entity->getGlobalBounds().width)) / 35, -1);
		if (this->getPosition().x + 1.5f * entity->getGlobalBounds().width <= entity->getPosition().x)
			reinterpret_cast<Ball*>(entity)->BouncePannel(abs(entity->getPosition().x - (this->getPosition().x + 1.5f * entity->getGlobalBounds().width)) / 35, -1);
		break;
	}
}

