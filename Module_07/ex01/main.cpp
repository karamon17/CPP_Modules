#include "iter.hpp"

int main( void ) {
	double array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print);
	std::cout << std::endl;
	iter(array, 5, add);
	iter(array, 5, print);
	std::cout << std::endl;
	iter(array, 5, sub);
	iter(array, 5, print<const int>);
	std::cout << std::endl;

	char array2[] = {'a', 'b', 'c', 'd'};
	iter(array2, 4, print);
	std::cout << std::endl;
	iter(array2, 4, add);
	iter(array2, 4, print);
	std::cout << std::endl;
	iter(array2, 4, sub);
	iter(array2, 4, print);
	std::cout << std::endl;

	std::string array3[] = {"Hello", "World", "!"};
	iter(array3, 3, print);
	std::cout << std::endl;
	return 0;
}