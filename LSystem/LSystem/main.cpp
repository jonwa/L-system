#include <iostream>
#include <SFML\Graphics.hpp>

#include "FractalPlantTurtle.h"
#include "SierpinskiTriangleTurtle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "L-System");

	sf::Vertex line[2];
	line[0].color = sf::Color::Green;
	line[1].color = sf::Color::Green;

	FractalPlantTurtle fractalPlant(270.0, window.getSize().x / 2, window.getSize().y);
	SierpinskiTriangleTurtle sierpinskiTriangle(270.0, window.getSize().x / 4, window.getSize().y);

	auto &result = fractalPlant.generate(6); 
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (auto &vertex : result)
		{
			line[0].position.x = static_cast<float>(vertex.x1);
			line[0].position.y = static_cast<float>(vertex.y1);
			line[1].position.x = static_cast<float>(vertex.x2);
			line[1].position.y = static_cast<float>(vertex.y2);
			window.draw(line, 2, sf::Lines);
		}
		window.display();
	}

	return 0;
}