#pragma once

#include <map>

template<class Element, class Sequence> class LSystem
{
	Sequence _state;
	std::map<Element, Sequence> _rules;

public:
	LSystem();
	~LSystem();

	void iterate(int n_);
	void add_rule(Element elem_, Sequence seq_);

	Sequence &get_state();
	Sequence &replace(Element &elem_);
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
void LSystem<Element, Sequence>::iterate(int n_)
{
	Sequence next;

	for (int i = 0; i < n_; ++i)
	{
		auto &result = replace(_state[i]);
		for (int j = 0; j < result.size(); ++j)
		{
			next.push_back(result[j]);
		}
	}

	_state = next;
}

template<class Element, class Sequence>
void LSystem<Element, Sequence>::add_rule(Element elem_, Sequence seq_)
{
	_rules.insert(std::make_pair(elem_, seq_));
}

template<class Element, class Sequence>
Sequence &LSystem<Element, Sequence>::get_state()
{
	return _state;
}

template<class Element, class Sequence>
Sequence &LSystem<Element, Sequence>::replace(Element &elem_)
{
	auto& it = _rules.find(elem_);
	if (it == std::end(_rules))
	{
		return it->second;
	}
	else
	{
		static Sequence ret;
		ret.clear();
		ret.push_back(elem_);
		return ret;
	}
}