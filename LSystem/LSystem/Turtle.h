#pragma once

#include "LSystem.h"
#include "Renderer.h"

enum Examples
{
	PYTHAGORAS_TREE,
	KOCH_CURVE,
	SIERPINISKI_TRIANGLE,
	DRAGON_CURVE,
	FRACTAL_PLANT
};

template<class Element, class Sequence>
class Turtle
{
	LSystem<Element, Sequence> _system;
	Renderer _renderer;
	Examples _example;
public:
	Turtle(Examples example_);
	~Turtle();
	
	void draw();
};

template<class Element, class Sequence>
Turtle<Element, Sequence>::Turtle(Examples example_)
	:_example(example_)
{
	LSystem<char, std::string> system;

	switch (_example)
	{
	case PYTHAGORAS_TREE:
		system.set_start("0");
		system.add_rule('1', "11");
		system.add_rule('0', "1[0]0");
		system.iterate(7);
		break;

	case KOCH_CURVE:
		system.set_start("F");
		system.add_rule('F', "F+F-F-F+F");
		system.iterate(3);
		break;

	case SIERPINISKI_TRIANGLE:
		system.set_start("F-G-G");
		system.add_rule('F', "F-G+F+G-F");
		system.add_rule('G', "GG");
		system.iterate(2);
		break;

	case DRAGON_CURVE:
		system.set_start("FX");
		system.add_rule('X', "X+YF+");
		system.add_rule('Y', "-FX-Y");
		system.iterate(10);
		break;

	case FRACTAL_PLANT:
		system.set_start("X");
		system.add_rule('X', "F-[[X]+X]+F[+FX]-X");
		system.add_rule('F', "FF");
		system.iterate(6);
		break;
	}
}

template<class Element, class Sequence>
Turtle<Element, Sequence>::~Turtle()
{
}

template<class Element, class Sequence>
void Turtle<Element, Sequence>::draw()
{
	double distance = 1.0;

	for (auto next : _system.get_state())
	{
		if (_example == Examples::PYTHAGORAS_TREE)
		{
			switch (next)
			{
			case '0':
				_renderer.move_forward(distance);
				break;
			case '1':
				_renderer.move_forward(distance);
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
		else if (_example == Examples::KOCH_CURVE)
		{
			switch (next)
			{
			case 'F':
				_renderer.move_forward(distance);
				break;
			case '+': 
				_renderer.rotate(-90.0);// turn left
				break;
			case '-': 
				_renderer.rotate(90.0);// turn right
				break;
			}
		}
		else if (_example == Examples::SIERPINISKI_TRIANGLE)
		{
			switch (next)
			{
			case 'F':
				_renderer.move_forward(distance);
				break;
			case 'G':
				_renderer.move_forward(distance);
				break;
			case '+': 
				_renderer.rotate(-120.0f);// turn left
				break;
			case '-': 
				_renderer.rotate(120.0f);// turn right
				break;
			}
		}
		else if (_example == Examples::DRAGON_CURVE)
		{
			switch (next)
			{
			case 'F':
				_renderer.move_forward(distance);
				break;
			case '-':
				_renderer.rotate(-90.0);//turn left
				break;
			case '+':
				_renderer.rotate(90.0);//turn right
				break;
			}
		}
		else if (_example == Examples::FRACTAL_PLANT)
		{
			switch (next)
			{
			case 'F':
				_renderer.move_forward(distance);
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