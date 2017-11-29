#include "SoundEffectManager.h"

void SoundEffectManager::InitializeSoundEffect()
{
	this->bufferPaddle = new SoundBuffer;
	this->bufferPaddle->loadFromFile("Sounds/paddle_bounce.wav");
	this->soundPaddle = new Sound(*this->bufferPaddle);

	this->bufferDestroyBrick = new SoundBuffer;
	this->bufferDestroyBrick->loadFromFile("Sounds/GetScore.wav");
	this->soundDestroyBrick = new Sound(*this->bufferDestroyBrick);

	this->bufferDamageBrick = new SoundBuffer;
	this->bufferDamageBrick->loadFromFile("Sounds/Brick.wav");
	this->soundDamageBrick = new Sound(*this->bufferDamageBrick);

	this->bufferWall = new SoundBuffer;
	this->bufferWall->loadFromFile("Sounds/wall_bounce.wav");
	this->soundWall = new Sound(*this->bufferWall);

	this->bufferLoseLife = new SoundBuffer;
	this->bufferLoseLife->loadFromFile("Sounds/LoseLife.wav");
	this->soundLoseLife = new Sound(*this->bufferLoseLife);

	this->bufferWin = new SoundBuffer;
	this->bufferWin->loadFromFile("Sounds/Winner.wav");
	this->soundWin = new Sound(*this->bufferWin);
}

void SoundEffectManager::PlaySoundEffect(int index)
{
	switch (index)
	{
	case PaddleSound:
		this->soundPaddle->play();
		index = -1;
		break;
	case DestroySound:
		this->soundDestroyBrick->play();
		index = -1;
		break;
	case DamageSound:
		this->soundDamageBrick->play();
		index = -1;
		break;
	case WallSound:
		this->soundWall->play();
		index = -1;
		break;
	case LoseLifeSound:
		this->soundLoseLife->play();
		index = -1;
		break;
	case WinSound:
		this->soundWin->play();
		index = -1;
		break;
	}
}
SoundEffectManager::~SoundEffectManager()
{
	delete this->soundPaddle;
	delete this->bufferPaddle;
	delete this->bufferDestroyBrick;
	delete this->soundDestroyBrick;
	delete this->bufferDamageBrick;
	delete this->soundDamageBrick;
	delete this->bufferWall;
	delete this->soundWall;
	delete this->bufferLoseLife;
	delete this->soundLoseLife;
	delete this->bufferWin;
	delete this->soundWin;
}