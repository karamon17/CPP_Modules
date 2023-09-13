#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
	~MutantStack() {}
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this != &copy)
			std::stack<T>::operator=(copy);
		return (*this);
	}

	typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}
	iterator end()
	{
		return (std::stack<T>::c.end());
	}
	const_iterator begin() const
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator end() const
	{
		return (std::stack<T>::c.end());
	}
	reverse_iterator rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend()
	{
		return (std::stack<T>::c.rend());
	}
	const_reverse_iterator rbegin() const
	{
		return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator rend() const
	{
		return (std::stack<T>::c.rend());
	}
};

#endif