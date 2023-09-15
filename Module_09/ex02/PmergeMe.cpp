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
	while (var <= pairs.size() + 2)
	{
		std::vector<int> v;
		groups.push_back(v);
		i++;
		last = var;
		var = pow(2, i) - last;
	}
}

void PmergeMe::print_pairs(std::vector<std::pair<int, int> > &pairs)
{
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	std::cout << "Pairs: " << std::endl;
	while (it != pairs.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
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

void PmergeMe::binary_insert(std::vector<int> &sorted, int num, size_t var)
{
	std::vector<int> copy = sorted;
	copy.erase(copy.begin() + var, copy.end());
	int left = 0;
	int right = copy.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (copy[mid] < num && copy[mid + 1] > num)
		{
			sorted.insert(sorted.begin() + mid + 1, num);
			return ;
		}
		else if (copy[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}

	//версия без отсечения
	// (void) var;
	// int left = 0;
	// int right = sorted.size() - 1;
	// int mid;
	// while (left <= right)
	// {
	// 	mid = left + (right - left) / 2;
	// 	if (sorted[mid] < num && sorted[mid + 1] > num)
	// 	{
	// 		sorted.insert(sorted.begin() + mid + 1, num);
	// 		return ;
	// 	}
	// 	else if (sorted[mid] < num)
	// 		left = mid + 1;
	// 	else
	// 		right = mid - 1;
	// }
}

void PmergeMe::insert_in_sorted(std::vector<std::vector<int> > &groups, std::vector<int> &sorted)
{
	std::vector<std::vector<int> >::iterator it = groups.begin();
	size_t var = 4;
	size_t count = 0;
	int last;
	while (it != groups.end())
	{
		std::vector<int>::iterator it2 = it->begin();
		last = var;
		while (it2 != it->end())
		{
			binary_insert(sorted, *it2, var);
			var--;
			it2++;
		}
		count++;
		var = pow(2, count + 1) - last + 4;
		it++;
	}
}

void PmergeMe::print_groups(std::vector<std::vector<int> > &groups)
{
	std::vector<std::vector<int> >::iterator it = groups.begin();
	std::cout << "Groups: " << std::endl;
	while (it != groups.end())
	{
		std::vector<int>::iterator it2 = it->begin();
		while (it2 != it->end())
		{
			std::cout << *it2 << " ";
			it2++;
		}
		std::cout << std::endl;
		it++;
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
	insert_in_sorted(groups, sorted);
	std::cout << "After:  ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	//checker
	std::sort(v.begin(), v.end());
	print(v);
	return 0;
}