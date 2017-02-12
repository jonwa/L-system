#include "Turtle.h"
#include "SFML\Window.hpp"

namespace LSystem
{
	namespace Examples
	{
		class PythagorasTreeTurtle: public Turtle<char, std::string>
		{
		public:
			void init(int iterations_);
			void draw(const sf::Window& window);
		};

		void PythagorasTreeTurtle::init(int iterations_)
		{
			_system.set_state("0");
			_system.add_rule('1', "11");
			_system.add_rule('0', "1[0]0");
			_system.iterate(iterations_);
		}

		void PythagorasTreeTurtle::draw(const sf::Window& window)
		{
			for (auto next : _system.get_state())
			{
				switch (next)
				{
				case '0':
					_renderer.move_forward(1.0);
					break;
				case '1':
					_renderer.move_forward(1.0);
					break;
				case '[':
					_renderer.push();
					_renderer.rotate(-45.0); //turn left
					break;
				case ']':
					_renderer.pop();
					_renderer.rotate(-45.0); //turn right
					break;
				}
			}
		}
	}
}