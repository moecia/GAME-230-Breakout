#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Lives.h"
#include "SoundEffectManager.h"

class Paddle : public Entity
{
public:
	Paddle(sf::RenderWindow* window, EntityManager* gameObjManager, SoundEffectManager* SEManager);
	bool Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	SoundEffectManager* SEManager;
	float velocityPaddle_keyboard = 4.0f;
	float velocityPaddle_mouse = 4.0f;
	EntityManager* gameObjManager;
	float direction;
};

