#include <Windows.h>

#include "GameState.h"
#include "MainMenu.h"
#include "Breakout.h"
CurrentState _currentState; 
bool quitGame = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 768), "Breakout");

	_currentState.SetWindow(&window);
	_currentState.SetState(new MainMenu());

	score = 0;
	live = 3;
	difficulty = 1;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		_currentState.Update();
		_currentState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}

		Sleep(5);
	}

	return 0;
}
