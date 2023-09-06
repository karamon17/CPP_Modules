#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char *what() const throw() { return ("Out of bounds"); }
	};

public:
	Array(void) : _array(NULL), _size(0) {}
	Array(unsigned int n) : _array(new T[n]), _size(n) {}
	Array(Array const &other) : _array(NULL), _size(0) { *this = other; }
	~Array(void) { delete [] _array; }
	Array &operator=(Array const &other)
	{
		if (this != &other)
		{
			delete [] _array;
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		return (*this);
	}
	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw OutOfBoundsException();
		return (_array[i]);
	}
	unsigned int size(void) const { return (_size); }
};

#endif