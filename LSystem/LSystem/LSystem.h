#pragma once

#include <map>

namespace LSystem
{
	template<class Element, class Sequence>
	class LSystem
	{
		Sequence _state;
		std::map<Element, Sequence> _rules;
	public:
		LSystem();
		~LSystem();

		void iterate(int i_);
		void add_rule(Element elem_, Sequence seq_);
		void set_state(Sequence state_) { _state = state_; }

		const Sequence& get_state() { return _state; }
		const Sequence replace(const Element& elem_);
	};

	template<class Element, class Sequence>
	LSystem<Element, Sequence>::LSystem()
	{
	}

	template<class Element, class Sequence>
	LSystem<Element, Sequence>::~LSystem()
	{
	}

	template<class Element, class Sequence>
	void LSystem<Element, Sequence>::iterate(int i_)
	{
		Sequence next;

		int i = 0;
		while (i < i_)
		{
			for (int j = 0; j < _state.size(); ++j)
			{
				auto result = replace(_state[j]);
				for (int k = 0; k < result.size(); ++k)
				{
					next.push_back(result[k]);
				}
			}
			_state = next;
			i++;
		}
	}

	template<class Element, class Sequence>
	void LSystem<Element, Sequence>::add_rule(Element elem_, Sequence seq_)
	{
		_rules.insert(std::make_pair(elem_, seq_));
	}

	template<class Element, class Sequence>
	const Sequence LSystem<Element, Sequence>::replace(const Element& elem_)
	{
		auto it = _rules.find(elem_);
		if (it != _rules.end())
		{
			return it->second;
		}

		Sequence ret;
		ret.push_back(elem_);
		return ret;
	}
}