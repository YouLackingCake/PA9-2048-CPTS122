#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Tile.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048!");  // Window is 500 by 500

	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music

	while (window.isOpen())  // Loop while window is open
	{
		sf::Event event;  // Declare an event type
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)  // Check for the window to close
				window.close();  // Close window
		}

		window.clear();

		//draw statements

		window.display();
	}

	return 0;
}