#pragma once

#include <stack>
#include <vector>
#include <math.h>

#define PI 3.141592653589793

struct Vertex
{
	double x1;
	double y1;
	double x2;
	double y2;
};

class Renderer
{
private:
	struct State
	{
		double angle;
		double x;
		double y;

		State(double angle_, double x_, double y_) 
			:angle(angle_)
			,x(x_)
			,y(y_)
		{ }
	};
private:
	std::stack<State> _states;
	std::vector<Vertex> _vertices;
public:
	Renderer(double start_angle_, double start_x_, double start_y_)
	{
		State state(start_angle_, start_x_, start_y_);
		_states.push(state);
	}

	~Renderer() { }

	void pop()
	{
		_states.pop();
	}

	void push()
	{
		State state(_states.top());
		_states.push(state);
	}

	void rotate(double angle_)
	{
		_states.top().angle += angle_;
	}
	
	void move_forward(double distance_)
	{
		const double rad = _states.top().angle * (PI / 180.0);

		Vertex result;
		result.x1 = _states.top().x;
		result.y1 = _states.top().y;
		result.x2 = _states.top().x + std::cos(rad) * distance_;
		result.y2 = _states.top().y + std::sin(rad) * distance_;

		_states.top().x = result.x2;
		_states.top().y = result.y2;

		_vertices.push_back(result);
	}

	const std::vector<Vertex> &get_vertices() const
	{
		return _vertices;
	}
};