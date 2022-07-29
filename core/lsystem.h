#pragma once

#include <map>
#include <stddef.h>

template<class Element, class Sequence>
class lsystem 
{
public:
	lsystem(Sequence axoim);
	
	void add_rule(Element element, Sequence sequence);
	const Sequence iterate(int iterations) const;
	const Sequence *replace(const Element& element) const;

private:
	Sequence _axiom;
	std::map<Element, Sequence> _rules;
};


template<class Element, class Sequence>
lsystem<Element, Sequence>::lsystem(Sequence axiom)
	: _axiom(axiom)
{
}

template<class Element, class Sequence>
void lsystem<Element, Sequence>::add_rule(Element element, Sequence sequence)
{
	_rules.insert(std::make_pair(element, sequence));
}

template<class Element, class Sequence>
const Sequence lsystem<Element, Sequence>::iterate(int iterations) const
{
	Sequence result = _axiom;
	Sequence next;
	
	for (int i = 0; i < iterations; ++i)
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
const Sequence* lsystem<Element, Sequence>::replace(const Element& element) const
{
	auto it = _rules.find(element);
	if (it != _rules.end())
	{
		return &it->second;
	}

	return nullptr;
}