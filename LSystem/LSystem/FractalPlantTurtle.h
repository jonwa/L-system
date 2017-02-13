#include "Turtle.h"

class FractalPlantTurtle : public Turtle<char, std::string>
{

public:
	FractalPlantTurtle(double start_angle_, double start_x_, double start_y_)
		: Turtle(start_angle_, start_x_, start_y_)
	{ 
		_system->set_start("X");
		_system->add_rule('X', "F-[[X]+X]+F[+FX]-X");
		_system->add_rule('F', "FF");
	}

	const std::vector<Vertex> &generate(int iterations_) const override
	{
		auto &result = _system->iterate(iterations_);

		for (auto &next : result)
		{
			switch (next)
			{
			case 'F':
				_renderer->move_forward(2.0);
				break;
			case '-':
				_renderer->rotate(-25.0);
				break;
			case '+':
				_renderer->rotate(25.0);
				break;
			case '[':
				_renderer->push();
				break;
			case ']':
				_renderer->pop();
				break;
			}
		}

		return _renderer->get_vertices();
	}
};