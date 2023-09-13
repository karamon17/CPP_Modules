#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_n = copy._n;
		_v = copy._v;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (_v.size() < _n)
		_v.push_back(num);
	else
		throw std::exception();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) <= _n)
		_v.insert(_v.end(), begin, end);
	else
		throw std::exception();
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw std::exception();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw std::exception();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}