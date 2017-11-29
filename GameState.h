#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class State
{
public:
	virtual void Initialize(RenderWindow* window)
	{
	}

	virtual void Update(RenderWindow* window)
	{
	}

	virtual void Render(RenderWindow* window)
	{
	}

	virtual void Destroy(RenderWindow* window)
	{
	}
	~State()
	{
	}
};

class CurrentState
{
public:
	CurrentState()
	{
		this->state = NULL;
	}

	void SetWindow(RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(State* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
		this->state = state;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}

	void Update()
	{
		if (this->state != NULL)
			this->state->Update(this->window);
	}

	void Render()
	{
		if (this->state != NULL)
			this->state->Render(this->window);
	}

	~CurrentState()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

private:
	RenderWindow* window;
	State *state;
};

extern CurrentState _currentState;
extern bool quitGame;