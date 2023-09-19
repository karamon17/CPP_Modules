#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"

int main(int argc, char **argv) {
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	PmergeMe::sort(argv, argc);
	PmergeMeList::sort(argv, argc);
    return 0;
}