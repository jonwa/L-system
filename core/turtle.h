#pragma once

#include <cmath>
#include <functional>
#include <map>
#include <stack>
#include <vector>

#define PI 3.141592653589793

struct point 
{
	double x;
	double y;

	point(double x, double y) 
		: x(x)
		, y(y)
	{
	}
};

struct line 
{
	point a;
	point b;

	line(point a, point b) 
		: a(a)
		, b(b)
	{
	}
};

struct state
{
	double angle;
	double x;
	double y;

	state(double angle, double x, double y)
		: angle(angle)
		, x(x)
		, y(y)
	{
	}
};

typedef std::function<void()> command_t;

template<class Element, class Sequence>
class turtle 
{
public:
	turtle(Sequence sequence, double angle);

	void add_command(Element element, command_t const& command);
	const std::vector<line>& interpret() const;

	void pop();
	void push();
	void rotate(double angle);
	void forward(double distance, bool draw);

private:
	double _angle;
	Sequence _sequence;
	std::vector<line> _lines;
	std::stack<state> _states;
	std::map<Element, command_t> _commands;
};


template<class Element, class Sequence>
turtle<Element, Sequence>::turtle(Sequence sequence, double angle) 
	: _sequence(sequence)
	, _angle(angle)
{ 
	state start(angle, 0.0, 0.0);
	_states.push(start);
}

template<class Element, class Sequence>
void turtle<Element, Sequence>::add_command(Element element, command_t const& command)
{
	_commands.insert(std::make_pair(element, command));
}

template<class Element, class Sequence>
const std::vector<line>& turtle<Element, Sequence>::interpret() const
{
	for (auto& next : _sequence)
	{
		auto it = _commands.find(next);
		if (it != _commands.end())
		{
			(it->second)();
		}
	}

	return _lines;
}

template<class Element, class Sequence>
void turtle<Element, Sequence>::pop()
{
	_states.pop();
}

template<class Element, class Sequence>
void turtle<Element, Sequence>::push()
{
	state next(_states.top());
	_states.push(next);
}

template<class Element, class Sequence>
void turtle<Element, Sequence>::rotate(double angle)
{
	_states.top().angle += angle;
}

template<class Element, class Sequence>
void turtle<Element, Sequence>::forward(double distance, bool draw)
{
	state& s = _states.top();
	const double rad = s.angle * (PI / 180.0);

	point a(s.x, s.y);
	point b(s.x + (distance * cos(rad)), s.y + (distance * sin(rad)));

	s.x = b.x;
	s.y = b.y;

	if (draw) 
	{
		line l(a, b);
		_lines.push_back(l);
	}
}
