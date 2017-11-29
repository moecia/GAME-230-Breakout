#pragma once
#include <SFML/Audio.hpp>

#define PaddleSound 0
#define DestroySound 1
#define DamageSound 2
#define WallSound 3
#define LoseLifeSound 4
#define WinSound 5
using namespace sf;
class SoundEffectManager
{
public:
	void InitializeSoundEffect();
	void PlaySoundEffect(int index);
	~SoundEffectManager();
private:

	SoundBuffer* bufferPaddle;
	Sound* soundPaddle;

	SoundBuffer* bufferDestroyBrick;
	Sound* soundDestroyBrick;

	SoundBuffer* bufferDamageBrick;
	Sound* soundDamageBrick;

	SoundBuffer* bufferWall;
	Sound* soundWall;

	SoundBuffer* bufferLoseLife;
	Sound* soundLoseLife;

	SoundBuffer* bufferWin;
	Sound* soundWin;	
};