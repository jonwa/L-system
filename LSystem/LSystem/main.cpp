#include "LSystem.h"
#include "TurtleRenderer.h"
#include <SFML\Graphics.hpp>

void pythagoras_tree()
{
	LSystem<char, std::string> system;
	system.add_rule('1', "11");
	system.add_rule('0', "1[0]0");
	system.iterate(7);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case '0':
			// draw a line segment ending in a leaf
			break;
		case '1':
			// draw a line segment
			break;
		case '[':
			// push position and angle turn left 45 deg
			break;
		case ']':
			// pop position and angle turn right 45 deg
			break;
		}
	}
}

void cantor_set()
{
	LSystem<char, std::string> system;
	system.add_rule('A', "ABA");
	system.add_rule('B', "BBB");
	system.iterate(10);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case 'A':
			renderer.draw_forward(1.0);
			break;
		case 'B':
			renderer.move_forward(1.0);
			break;
		}
	}
}

void koch_curve()
{
	LSystem<char, std::string> system;
	system.add_rule('F', "F+F-F-F+F");
	system.iterate(3);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case 'F':
			renderer.draw_forward(1.0);
			break;
		case '+': // turn left 90 deg
			renderer.rotate(-90.0);
			break;
		case '-': // turn right 90 deg
			renderer.rotate(90.0);
			break;
		}
	}
}

void sierpinski_triangle()
{
	LSystem<char, std::string> system;
	system.add_rule('F', "F-G+F+G-F");
	system.add_rule('G', "GG");
	system.iterate(2);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case 'F':
			renderer.draw_forward(1.0);
			break;
		case 'G':
			renderer.draw_forward(1.0);
			break;
		case '+': // turn left by 60 deg
			renderer.rotate(-60.0);
			break;
		case '-': // turn right by 60 deg
			renderer.rotate(60.0);
			break;
		}
	}
}

void dragon_curve()
{
	LSystem<char, std::string> system;
	system.add_rule('X', "X+YF+");
	system.add_rule('Y', "-FX-Y");
	system.iterate(10);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case 'F':
			renderer.draw_forward(1.0);
			break;
		case 'X':
			// noop
			break;
		case 'Y':
			// noop
			break;
		case '+': // turn right by 90 deg
			renderer.rotate(90.0);
			break;
		case '-': // turn left by 90 deg
			renderer.rotate(-90.0);
			break;
		}
	}
}

void fractal_plant()
{
	LSystem<char, std::string> system;
	system.add_rule('X', "F-[[X]+X]+F[+FX]-X");
	system.add_rule('F', "FF");
	system.iterate(6);

	TurtleRenderer renderer;
	auto &state = system.get_state();
	for (auto i : state)
	{
		switch (i)
		{
		case 'F': // draw forward
			renderer.draw_forward(1.0);
			break;
		case 'X':
			// noop
			break;
		case '[':
			// save current values for position and angle
			break;
		case ']':
			// restore position and angle from last '['
			break;
		case '+': // turn right by 25 deg
			renderer.rotate(25.0);
			break;
		case '-': // turn left by 25 deg
			renderer.rotate(-25.0);
			break;
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "L-System");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}