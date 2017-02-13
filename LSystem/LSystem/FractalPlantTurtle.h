#include "Turtle.h"
#include "SFML\Window.hpp"

namespace LSystem
{
	namespace Examples
	{
		class FractalPlantTurtle : public Turtle<char, std::string>
		{
		public:
			void init(int iterations_);
			void draw(const sf::Window& window_);
		};

		void FractalPlantTurtle::init(int iterations_)
		{
			_system.set_state("X");
			_system.add_rule('X', "F-[[X]+X]+F[+FX]-X");
			_system.add_rule('F', "FF");
			_system.iterate(iterations_);
		}

		void FractalPlantTurtle::draw(const sf::Window& window_)
		{
			for (auto next : _system.get_state())
			{
				switch (next)
				{
				case 'F':
					_renderer.draw_forward(window_, 1.0);
					break;
				case '-':
					_renderer.rotate(-25.0);//turn left
					break;
				case '+':
					_renderer.rotate(25.0);//turn right
					break;
				case '[':
					_renderer.push();
					break;
				case ']':
					_renderer.pop();
					break;
				}
			}
		}
	}
}