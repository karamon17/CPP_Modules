#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	(void) argc;
    return PmergeMe::sort(argv, argc);
}