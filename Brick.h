#pragma once
#include "Entity.h"
#define normalBrick 0
#define movingBrick 1
#define invincibleBrick 2
#define invisibleBrick 3

extern int bricksDestroyed;

class Brick : public Entity
{
public:
	Brick(float x, float y, int brickType);
	bool Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
	int health;
protected:
	sf::Vector2f position;
	int brickType;
	int maxHealth;
private:	
	bool movingLeft = false;
	bool movingRight = true;
};

