#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void print(T &x)
{
	std::cout << x << ' ';
}

template <typename T>
void add(T &x)
{
	x += 1;
}

template <typename T>
void sub(T &x)
{
	x -= 1;
}

template <typename T>
void iter(T *array, int length, void (*f)(T &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif