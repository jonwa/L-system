#include <iostream>
#include <SFML\Graphics.hpp>

#include "Examples.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "L-System");

	auto& turtle = LSystem::Examples::PythagorasTreeTurtle();
	turtle.init(10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		turtle.draw(window);
		window.display();
	}

	return 0;
}