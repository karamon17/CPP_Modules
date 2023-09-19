#include "PmergeMeList.hpp"

PmergeMeList::PmergeMeList() {

}

PmergeMeList::PmergeMeList(PmergeMeList const &src) {
	*this = src;
}

PmergeMeList::~PmergeMeList() {

}

PmergeMeList &PmergeMeList::operator=(PmergeMeList const &rhs) {
	if (this != &rhs) {
		 
	}
	return *this;
}

void PmergeMeList::print(std::list<int> &l)
{
	std::list<int>::iterator it = l.begin();
	std::cout << "Before: ";
	while (it != l.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMeList::check(std::list<int> &l)
{
	std::list<int>::iterator it = l.begin();
	std::set<int> s;
	while (it != l.end())
	{
		if (*it <= 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			exit (1);
		}
		s.insert(*it);
		it++;
	}
	if (s.size() != l.size())
	{
		std::cerr << "Error: input has duplicates" << std::endl;
		exit (1);
	}
}

void PmergeMeList::fill_list(char **argv, std::list<int> &l)
{
	argv++;
	while (*argv)
	{
		l.push_back(std::atoi(*argv));
		argv++;
	}
}

void PmergeMeList::fill_pairs(std::list<int> &l, std::list<std::pair<int, int> > &pairs)
{
	std::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		std::pair<int, int> p;
		p.first = *it;
		it++;
		if (it != l.end()) {
			p.second = *it;
			it++;
		}
		pairs.push_back(p);
	}
}

void PmergeMeList::sort_pairs(std::list<std::pair<int, int> > &pairs)
{
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
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

void PmergeMeList::amount_of_groups(std::list<std::pair<int, int> > &pairs, std::list<std::list<int> > &groups)
{
	size_t var = 2;
	int i = 1;
	int last;
	while (var <= pairs.size() + 2)
	{
		std::list<int> v;
		groups.push_back(v);
		i++;
		last = var;
		var = pow(2, i) - last;
	}
}

void PmergeMeList::print_pairs(std::list<std::pair<int, int> > &pairs)
{
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	std::cout << "Pairs: " << std::endl;
	while (it != pairs.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}

void PmergeMeList::devide_to_groups(std::list<std::pair<int, int> > &pairs, std::list<std::list<int> > &groups)
{
	size_t count = 0;
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	amount_of_groups(pairs, groups);
	size_t var = 2;
	int last;
	std::list<std::list<int> >::iterator it2 = groups.begin();
	for (; it2 != groups.end(); it2++)
	{
		for (size_t i = 0; i < var && it != pairs.end(); i++, it++)
		{
			if (it->second != 0)
				it2->push_front(it->second);
		}
		last = var;
		count++;
		var = pow(2, count + 1) - last;
	}
}

void PmergeMeList::binary_insert(std::list<int> &sorted, int num, int group_index)
{
	std::list<int> copy = sorted;
	size_t i = pow(2, group_index) - 1;
	std::list<int>::iterator it = copy.begin();
	std::list<int>::iterator it2 = sorted.begin();
	std::list<int>::iterator it3 = sorted.begin();
	std::advance(it, i);
    if (i < sorted.size())
	    copy.erase(it, copy.end());
	int left = 0;
	int right = copy.size();
	size_t mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		it2 = sorted.begin();
		std::advance(it2, mid);
		it3 = it2;
		std::advance(it3, 1);
		if (*it2 < num && mid + 1 < sorted.size() && *(it3) > num)
		{
			sorted.insert(it3, num);
			return ;
		}
		else if (left == right)
		{
			it2 = sorted.begin();
			std::advance(it2, left);
			sorted.insert(it2, num);
			return ;
		}
		else if (*(it2) < num)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

void PmergeMeList::insert_in_sorted(std::list<std::list<int> > &groups, std::list<int> &sorted)
{
	std::list<std::list<int> >::iterator it = groups.begin();
	int group_index = 2;
	while (it != groups.end())
	{
		std::list<int>::iterator it2 = it->begin();
		while (it2 != it->end() && *it2 != 0)
		{
			binary_insert(sorted, *it2, group_index);
			it2++;
		}
		group_index++;
		it++;
	}
	if (*(sorted.begin()) == 0)
		sorted.erase(sorted.begin());
}

void PmergeMeList::print_groups(std::list<std::list<int> > &groups)
{
	std::list<std::list<int> >::iterator it = groups.begin();
	std::cout << "Groups: " << std::endl;
	while (it != groups.end())
	{
		std::list<int>::iterator it2 = it->begin();
		while (it2 != it->end())
		{
			std::cout << *it2 << " ";
			it2++;
		}
		std::cout << std::endl;
		it++;
	}
}

void PmergeMeList::merge(std::list<std::pair<int, int> > &pairs, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::list<std::pair<int, int> > L;
	std::list<std::pair<int, int> > R;
	std::list<std::pair<int, int> >::iterator it, it2, it3;
	for (i = 0; i < n1; i++)
	{
		it = pairs.begin();
		std::advance(it, left + i);
		L.push_back(*it);
	}
	for (j = 0; j < n2; j++)
	{
		it = pairs.begin();
		std::advance(it, mid + 1 + j);
		R.push_back(*it);
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		it = L.begin();
		std::advance(it, i);
		it2 = R.begin();
		std::advance(it2, j);
		if (it->first <= it2->first)
		{
			it3 = pairs.begin();
			std::advance(it3, k);
			*it3 = *it;
			i++;
		}
		else
		{
			it3 = pairs.begin();
			std::advance(it3, k);
			*it3 = *it2;
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		it = L.begin();
		std::advance(it, i);
		it3 = pairs.begin();
		std::advance(it3, k);
		*it3 = *it;
		i++;
		k++;
	}
	while (j < n2)
	{
		it2 = R.begin();
		std::advance(it2, j);
		it3 = pairs.begin();
		std::advance(it3, k);
		*it3 = *it2;
		j++;
		k++;
	}
}

void PmergeMeList::merge_sort(std::list<std::pair<int, int> > &pairs, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(pairs, left, mid);
		merge_sort(pairs, mid + 1, right);
		merge(pairs, left, mid, right);
	}
}

void PmergeMeList::insert(std::list<std::pair<int, int> > &pairs, std::list<int> &new_v)
{
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		new_v.push_back(it->first);
		it++;
	}
	new_v.insert(new_v.begin(), pairs.begin()->second);
	pairs.erase(pairs.begin());
}

bool PmergeMeList::areVectorsEqual(const std::set<int>& vector1, const std::set<int>& vector2) {
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

void PmergeMeList::checker(std::list<int>& l, std::list<int>& sorted)
{
	l.sort();
	std::set<int> set(l.begin(), l.end());
	std::set<int> set_sorted(sorted.begin(), sorted.end());
	if (areVectorsEqual(set, set_sorted)) {
        std::cout << "Векторы равны." << std::endl;
    } else {
        std::cout << "Векторы не равны." << std::endl;
    }
}

void PmergeMeList::sort(char **argv, int argc)
{
	clock_t start = clock();
	std::list<int> l;
	std::list<int> sorted;
	fill_list(argv, l);
	//check(l);
	//print(l);
	std::list<std::pair<int, int> > pairs;
	fill_pairs(l, pairs);
	sort_pairs(pairs);
	merge_sort(pairs, 0, pairs.size() - 1);
	insert(pairs, sorted);
	std::list<std::list<int> > groups;
	devide_to_groups(pairs, groups);
	insert_in_sorted(groups, sorted);
	// std::cout << "After:  ";
	// std::list<int>::iterator it = sorted.begin();
	// while (it != sorted.end())
	// {
	// 	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << std::endl;

	//checker(l, sorted);
	
	clock_t end = clock();
	double time = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time << " us" << std::endl;
}