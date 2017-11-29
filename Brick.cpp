#include "MainGame.h"
#include "Brick.h"
#include "Score.h"

Brick::Brick(float x, float y, int brickType)
{
	this->brickType = brickType;
	switch (brickType)
	{
	case normalBrick:
		this->setColor(sf::Color::Blue);
		this->health = 1;
		this->maxHealth = 1;
		break;
	case movingBrick:
		this->setColor(sf::Color::White);
		break;
	case invincibleBrick:
		this->setColor(sf::Color::Yellow);
		break;
	case invisibleBrick:
		this->setColor(sf::Color::Black);
		this->health = 2;
		this->maxHealth = 2;
		break;
	}
	this->position = sf::Vector2f(x, y);
	this->Load("Brick.png");
	this->setScale(0.3f, 0.5f);
	
	this->setPosition(x, y);
	this->groupId = 2;
	
}

bool Brick::Update(sf::RenderWindow* window)
{
	sf::Color color = this->getColor();
	switch (brickType)
	{
	case invisibleBrick:
		this->setPosition(this->position.x - Entity::scroll.x, this->position.y - Entity::scroll.y);
		if (this->maxHealth - this->health == 1)
		{
			color.r = 128;
			color.b = 128;
			this->setColor(color);
		}
		break;
	case movingBrick:
		if (this->getPosition().x + this->getGlobalBounds().width >= 1280)
		{
			this->movingLeft = true;
			this->movingRight = false;
		}
		if (this->getPosition().x / 2 <= 5)
		{
			this->movingLeft = false;
			this->movingRight = true;
		}

		if (this->movingLeft == true)
		{
			this->move(-2.5f, 0);
		}
		if (this->movingRight == true)
			this->move(2.5f, 0);
		break;
	}
	if (this->health <= 0 && (this->brickType == normalBrick || this->brickType == invisibleBrick))
	{
		bricksDestroyed += 1;
		this->Destroy();
	}

	Entity::Update(window);
	return true;
}

void Brick::Collision(Entity* entity)
{
}

