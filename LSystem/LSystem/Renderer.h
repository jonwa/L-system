#pragma once

#include <stack>
#include <SFML\Window\Window.hpp>
#include <SFML\System\Vector2.hpp>

namespace LSystem
{
	class Renderer
	{
		struct State
		{
			double get_angle() { return _angle; }
			sf::Vector2f get_position(){ return _position; }

			void set_angle(double angle_) { _angle = angle_; }
			void set_position(sf::Vector2f position_) { _position = position_; }
		private:
			sf::Vector2f _position;
			double _angle;
		};

		std::stack<State> _states;
	public:
		Renderer() { }
		~Renderer() { }

		void pop();
		void push();
		void rotate(double angle_);
		void draw_forward(const sf::Window& window_, double distance_);
	};
}

