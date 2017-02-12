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
	void set_start(Sequence start_);
	void add_rule(Element elem_, Sequence seq_);

	const Sequence &get_state();
	const Sequence &replace(const Element& elem_);
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

	auto i = 0;
	while (i < n_)
	{
		for (int j = 0; j < _state.size(); ++j)
		{
			auto &result = replace(_state[j]);
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
void LSystem<Element, Sequence>::set_start(Sequence start_)
{
	_state = start_;
}

template<class Element, class Sequence>
void LSystem<Element, Sequence>::add_rule(Element elem_, Sequence seq_)
{
	_rules.insert(std::make_pair(elem_, seq_));
}

template<class Element, class Sequence>
const Sequence &LSystem<Element, Sequence>::get_state()
{
	return _state;
}

template<class Element, class Sequence>
const Sequence &LSystem<Element, Sequence>::replace(const Element& elem_)
{
	auto it = _rules.find(elem_);
	if (it != _rules.end())
	{
		return it->second;
	}
	
	static Sequence ret;
	ret.clear();
	ret.push_back(elem_);
	return ret;
}