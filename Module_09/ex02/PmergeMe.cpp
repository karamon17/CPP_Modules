#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {

}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		 
	}
	return *this;
}

void PmergeMe::sort(char **argv)
{
	std::vector<int> v;
	argv++;
	while (*argv)
	{
		v.push_back(std::atoi(*argv));
		argv++;
	}
	std::cout << v.size() << std::endl;
}