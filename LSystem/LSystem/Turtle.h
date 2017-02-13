#pragma once

#include "LSystem.h"
#include "Renderer.h"

namespace LSystem
{
	template<class Element, class Sequence>
	class Turtle
	{
	protected:
		LSystem<Element, Sequence> _system;
		Renderer _renderer;
	public:
		Turtle() { }
		~Turtle() { }

		void init(int iterations_);
		void draw(const sf::Window& window_);
	};
}
