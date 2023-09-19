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
			std::cerr << "Error: not a positive number" << std::endl;
			exit (1);
		}
		s.insert(*it);
		it++;
	}
	if (s.size() != v.size())
	{
		std::cerr << "Error: input has duplicates" << std::endl;
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
		{
			if (it->second != 0)
				groups[count].insert(groups[count].begin(), it->second);
		}
		last = var;
		count++;
		var = pow(2, count + 1) - last;
	}
}

void PmergeMe::binary_insert(std::vector<int> &sorted, int num, int group_index)
{
	std::vector<int> copy = sorted;
	size_t i = pow(2, group_index) - 1;
    if (i < sorted.size())
	    copy.erase(copy.begin() + i, copy.end());
	int left = 0;
	int right = copy.size();
	size_t mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sorted[mid] < num && mid + 1 < sorted.size() && sorted[mid + 1] > num)
		{
			sorted.insert(sorted.begin() + mid + 1, num);
			return ;
		}
		else if (left == right)
		{
			sorted.insert(sorted.begin() + left, num);
			return ;
		}
		else if (sorted[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

void PmergeMe::insert_in_sorted(std::vector<std::vector<int> > &groups, std::vector<int> &sorted)
{
	std::vector<std::vector<int> >::iterator it = groups.begin();
	int group_index = 2;
	while (it != groups.end())
	{
		std::vector<int>::iterator it2 = it->begin();
		while (it2 != it->end() && *it2 != 0)
		{
			binary_insert(sorted, *it2, group_index);
			it2++;
		}
		group_index++;
		it++;
	}
	if (sorted[0] == 0)
		sorted.erase(sorted.begin());
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

void PmergeMe::merge(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<std::pair<int, int> > L;
	std::vector<std::pair<int, int> > R;
	for (i = 0; i < n1; i++)
		L.push_back(pairs[left + i]);
	for (j = 0; j < n2; j++)
		R.push_back(pairs[mid + 1 + j]);
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i].first <= R[j].first)
		{
			pairs[k] = L[i];
			i++;
		}
		else
		{
			pairs[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		pairs[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		pairs[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::merge_sort(std::vector<std::pair<int, int> > &pairs, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(pairs, left, mid);
		merge_sort(pairs, mid + 1, right);
		merge(pairs, left, mid, right);
	}
}

void PmergeMe::insert(std::vector<std::pair<int, int> > &pairs, std::vector<int> &new_v)
{
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		new_v.push_back(it->first);
		it++;
	}
	new_v.insert(new_v.begin(), pairs.begin()->second);
	pairs.erase(pairs.begin());
}

bool PmergeMe::areVectorsEqual(const std::set<int>& vector1, const std::set<int>& vector2) {
    if (vector1.size() != vector2.size()) {
		std::cout << "\n" << vector1.size() << " " << vector2.size() << "\n" << std::endl;
        return false;
    }
	std::set<int>::iterator it1 = vector1.begin();
	std::set<int>::iterator it2 = vector2.begin();
	for (; it1 != vector1.end(); it1++, it2++)
		if (*it1 != *it2) {
			std::cout << "\n" << "Элемент " << *it1 << "\n" << std::endl;
            return false;
		}
    return true;
}

void PmergeMe::checker(std::vector<int>& v, std::vector<int>& sorted)
{
	std::sort(v.begin(), v.end());
	std::set<int> set(v.begin(), v.end());
	std::set<int> set_sorted(sorted.begin(), sorted.end());
	if (areVectorsEqual(set, set_sorted)) {
        std::cout << "Векторы равны." << std::endl;
    } else {
        std::cout << "Векторы не равны." << std::endl;
    }
}

void PmergeMe::sort(char **argv, int argc)
{
	clock_t start = clock();
	std::vector<int> v;
	std::vector<int> sorted;
	fill_vector(argv, v);
	check(v);
	print(v);
	std::vector<std::pair<int, int> > pairs;
	fill_pairs(v, pairs);
	sort_pairs(pairs);
	merge_sort(pairs, 0, pairs.size() - 1);
	insert(pairs, sorted);
	std::vector<std::vector<int> > groups;
	devide_to_groups(pairs, groups);
	insert_in_sorted(groups, sorted);
	std::cout << "After:  ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	//checker(v, sorted);
	
	clock_t end = clock();
	double time = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time << " us" << std::endl;
}