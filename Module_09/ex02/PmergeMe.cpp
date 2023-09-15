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

void PmergeMe::print(std::vector<int> &v)
{
	std::vector<int>::iterator it = v.begin();
	std::cout << "Before: ";
	while (it != v.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::check(std::vector<int> &v)
{
	std::vector<int>::iterator it = v.begin();
	std::set<int> s;
	while (it != v.end())
	{
		if (*it <= 0)
		{
			std::cerr << "Error" << std::endl;
			exit (1);
		}
		s.insert(*it);
		it++;
	}
	if (s.size() != v.size())
	{
		std::cerr << "Error" << std::endl;
		exit (1);
	}
}

void PmergeMe::fill_vector(char **argv, std::vector<int> &v)
{
	argv++;
	while (*argv)
	{
		v.push_back(std::atoi(*argv));
		argv++;
	}
}

void PmergeMe::fill_pairs(std::vector<int> &v, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		std::pair<int, int> p;
		p.first = *it;
		it++;
		if (it != v.end()) {
			p.second = *it;
			it++;
		}
		pairs.push_back(p);
	}
}

void PmergeMe::sort_pairs(std::vector<std::pair<int, int> > &pairs)
{
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		if (it->first < it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		it++;
	}
}

void PmergeMe::recursion(std::vector<std::pair<int, int> > &pairs, std::vector<int> &new_v)
{
	if (pairs.size() == 0)
		return ;
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	int min = it->first;
	while (it != pairs.end())
	{
		if (it->first < min)
			min = it->first;
		it++;
	}
	new_v.push_back(min);
	it = pairs.begin();
	while (it != pairs.end())
	{
		if (it->first == min)
			break ;
		it++;
	}
	pairs.erase(it);
	recursion(pairs, new_v);
}

void PmergeMe::insert_min(std::vector<std::pair<int, int> > &pairs, std::vector<int> &new_v)
{
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		if (it->first == new_v[0])
			break ;
		it++;
	}
	if (it->second != 0)
		new_v.insert(new_v.begin(), it->second);
	pairs.erase(it);
}

void PmergeMe::amount_of_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups)
{
	size_t var = 2;
	int i = 1;
	int last;
	while (var < pairs.size())
	{
		std::vector<int> v;
		groups.push_back(v);
		i++;
		last = var;
		var = pow(2, i) - last;
	}
}

void PmergeMe::devide_to_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups)
{
	size_t count = 0;
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	amount_of_groups(pairs, groups);
	size_t var = 2;
	int last;
	while (count < groups.size())
	{
		for (size_t i = 0; i < var && it < pairs.end(); i++, it++)
			groups[count].insert(groups[count].begin(), it->second);
		last = var;
		count++;
		var = pow(2, count + 1) - last;
	}
}

bool PmergeMe::sort(char **argv)
{
	std::vector<int> v;
	std::vector<int> sorted;
	fill_vector(argv, v);
	check(v);
	print(v);
	std::vector<std::pair<int, int> > pairs;
	fill_pairs(v, pairs);
	sort_pairs(pairs);
	std::vector<std::pair<int, int> > pairs_copy = pairs;
	recursion(pairs_copy, sorted);
	insert_min(pairs, sorted);
	std::vector<std::vector<int> > groups;
	devide_to_groups(pairs, groups);
	//std::cout << groups[0][0] << std::endl;
	return 0;
}