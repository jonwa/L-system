#pragma once

#include <map>

template<class Element, class Sequence>
class LSystem
{
private:
	Sequence _start;
	std::map<Element, Sequence> _rules;
public:
	LSystem() { }
	~LSystem() { }
	
	void set_start(Sequence state_);
	void add_rule(Element element_, Sequence sequence_);
	const Sequence iterate(int iterations_) const;
	const Sequence *replace(const Element& element_) const;
};

template<class Element, class Sequence>
void LSystem<Element, Sequence>::set_start(Sequence start_)
{
	_start = start_;
}

template<class Element, class Sequence>
void LSystem<Element, Sequence>::add_rule(Element element_, Sequence sequence_)
{
	_rules.insert(std::make_pair(element_, sequence_));
}

template<class Element, class Sequence>
const Sequence LSystem<Element, Sequence>::iterate(int iterations_) const
{
	Sequence result = _start;

	Sequence next;
	for (int i = 0; i < iterations_; ++i)
	{
		next.clear();
		for (size_t j = 0; j < result.size(); ++j)
		{
			auto replaced = replace(result.at(j));
			if (replaced == nullptr)
			{
				next.push_back(result.at(j));
			}
			else
			{
				for (size_t k = 0; k < replaced->size(); ++k)
				{
					next.push_back(replaced->at(k));
				}
			}
		}
		result = next;
	}

	return result;
}

template<class Element, class Sequence>
const Sequence *LSystem<Element, Sequence>::replace(const Element& element_) const
{
	auto it = _rules.find(element_);
	if (it != _rules.end())
	{
		return &it->second;
	}

	return nullptr;
}