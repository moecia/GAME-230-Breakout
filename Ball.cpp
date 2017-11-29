#include "Ball.h"
#include "Brick.h"
#include "MainMenu.h"
float difficulty;
Ball::Ball(Lives* lives, EntityManager* gameObjManager, SoundEffectManager* SEManager)
{
	this->gameObjManager = gameObjManager;
	this->SEManager = SEManager;
	this->active = 1;
	this->groupId = 3;
	this->Load("Ball.PNG");
	this->setScale(.1f, .1f);
	this->lives = lives;
}

void Ball::Bounce(float x, float y)
{
	if (x > 0)
	{
		this->velocity.x *= -x; // *difficulty);
	}
	if (y > 0)
	{
		this->velocity.y *= -y; // *difficulty);
	}
}

void Ball::BouncePannel(float x, float y)
{
	this->velocity.x = x; // *difficulty;
	this->velocity.y *= y; // *difficulty);
}

bool Ball::Update(sf::RenderWindow* window)
{
	this->Reset(window);
	if (this->getPosition().x <= 0 || this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
	{
		this->Bounce(1, -1);
		SEManager->PlaySoundEffect(WallSound);
	}
	if (this->getPosition().y <= 0)
	{
		this->Bounce(0, 1);
		SEManager->PlaySoundEffect(WallSound);
	}
	if (this->getPosition().y > 768 - 2 * this->gameObjManager->Get("Paddle")->getGlobalBounds().height)
	{
		this->lives->RemoveLife();
		SEManager->PlaySoundEffect(LoseLifeSound);
		this->Shoot = false;
		this->Reset(window);
	}
	Entity::Update(window);
	return true;
}

void Ball::Collision(Entity* entity)
{
	switch (entity->GroupID())
	{
	case 2:
		if (this->CollisionSide(entity, COL_LEFT) || this->CollisionSide(entity, COL_RIGHT))
		{
			if (this->CollisionSide(entity, COL_TOP) || this->CollisionSide(entity, COL_BOTTOM))
			{				
				reinterpret_cast<Brick*>(entity)->health -= 1;
				this->SEManager->PlaySoundEffect(DamageSound);
				this->Bounce(1, 1);
			}
			else
			{
				reinterpret_cast<Brick*>(entity)->health -= 1;
				this->SEManager->PlaySoundEffect(DamageSound);
				this->Bounce(1, 1);
			}
		}
		else if (this->CollisionSide(entity, COL_TOP) || this->CollisionSide(entity, COL_BOTTOM))
		{
			reinterpret_cast<Brick*>(entity)->health -= 1;
			this->SEManager->PlaySoundEffect(DamageSound);
			this->Bounce(1, 1);
		}
		break;
	}
}

void Ball::Reset(RenderWindow* window)
{
	if (Shoot == false)
	{
		this->setPosition(this->gameObjManager->Get("Paddle")->getPosition().x + 1.5f * this->getGlobalBounds().width, this->gameObjManager->Get("Paddle")->getPosition().y - this->getGlobalBounds().height);
		if (gameMode == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				ShootBall();
			}
		}
		else
		{
			if (Mouse::isButtonPressed(sf::Mouse::Left))
			{
				ShootBall();
			}
		}

	}
}

void Ball::ShootBall()
{
	this->velocity.x = cos(255 / 180.0f * 3.14f) * 3 * difficulty;
	this->velocity.y = sin(255 / 180.0f * 3.14f) * 3 * difficulty;
	Shoot = true;
}