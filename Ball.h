#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Lives.h"
#include "EntityManager.h"
#include "SoundEffectManager.h" 
using namespace sf;
class Ball : public Entity
{
public:
	Ball(Lives* lives, EntityManager* gameObjManager, SoundEffectManager* SEManager);
	bool Update(RenderWindow* window);
	void Collision(Entity* entity);
	void Bounce(float x, float y);
	void BouncePannel(float x, float y);
	bool Shoot = false;
	void Reset(RenderWindow* window);
	void ShootBall();
private:
	SoundEffectManager* SEManager;
	EntityManager* gameObjManager;
	Lives* lives;
};