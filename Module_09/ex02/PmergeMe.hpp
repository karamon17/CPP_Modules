#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class PmergeMe {

private:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

public:
	static void sort(char **argv);
};

#endif