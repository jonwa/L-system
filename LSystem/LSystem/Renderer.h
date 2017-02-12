#pragma once

#include <stack>
#include <SFML\System\Vector2.hpp>

class Renderer
{
	struct State
	{
		double get_angle() { return _angle; }
		sf::Vector2f get_position(){ return _position; }

		void set_angle(double angle_) { _angle = angle_; }
		void set_position(sf::Vector2f position_) { _position = position_; }
	private:
		double _angle;
		sf::Vector2f _position;
	};

	std::stack<State> _states;
public:
	Renderer();
	~Renderer();

	void pop();
	void push();
	void rotate(double angle_);
	void move_forward(double distance_);
};
