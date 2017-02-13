#include "Turtle.h"

class SierpinskiTriangleTurtle : public Turtle<char, std::string>
{
public:
	SierpinskiTriangleTurtle(double start_angle_, double start_x_, double start_y_)
		: Turtle(start_angle_, start_x_, start_y_)
	{
		_system->set_start("F-G-G");
		_system->add_rule('F', "F-G+F+G-F");
		_system->add_rule('G', "GG");
	}

	const std::vector<Vertex> &generate(int iterations_) const override
	{
		auto &result = _system->iterate(iterations_);

		for (auto &next : result)
		{
			switch (next)
			{
			case 'F':
				_renderer->move_forward(5.0);
				break;
			case 'G':
				_renderer->move_forward(5.0);
				break;
			case '+':
				_renderer->rotate(-120.0f);
				break;
			case '-':
				_renderer->rotate(120.0f);
				break;
			}
		}

		return _renderer->get_vertices();
	};
};