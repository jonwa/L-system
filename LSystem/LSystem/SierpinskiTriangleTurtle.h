#include "Turtle.h"
#include "SFML\Window.hpp"

namespace LSystem
{
	namespace Examples
	{
		class SierpinskiTriangleTurtle : public Turtle<char, std::string>
		{
		public:
			void init(int iterations_);
			void draw(const sf::Window& window_);
		};

		void SierpinskiTriangleTurtle::init(int iterations_)
		{
			_system.set_state("F-G-G");
			_system.add_rule('F', "F-G+F+G-F");
			_system.add_rule('G', "GG");
			_system.iterate(2);
		}

		void SierpinskiTriangleTurtle::draw(const sf::Window& window_)
		{
			for (auto next : _system.get_state())
			{
				switch (next)
				{
				case 'F':
					_renderer.draw_forward(window_, 1.0);
					break;
				case 'G':
					_renderer.draw_forward(window_, 1.0);
					break;
				case '+':
					_renderer.rotate(-120.0f);// turn left
					break;
				case '-':
					_renderer.rotate(120.0f);// turn right
					break;
				}
			}
		}
	}
}