#pragma once

#include "LSystem.h"
#include "Renderer.h"

template<class Element, class Sequence>
class Turtle
{
protected:
	Renderer *_renderer;
	LSystem<Element, Sequence> *_system;
public:
	Turtle(double start_angle_, double start_x_, double start_y_)
	{ 
		_renderer = new Renderer(start_angle_, start_x_, start_y_);
		_system = new LSystem<char, std::string>();
	}

	virtual ~Turtle()
	{
		delete _renderer;
		delete _system;
	}

	const virtual std::vector<Vertex> &generate(int iterations_) const = 0;
};