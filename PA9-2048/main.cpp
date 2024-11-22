
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Tile.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "PA9- 2048");//open window 1000x1000

	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music

	while (window.isOpen())//loop while window is open
	{
		sf::Event event;//declare an event type
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//check for the window to close
				window.close();//close window
		}

		window.clear();

		//draw statements

		window.display();
	}

	return 0;
}