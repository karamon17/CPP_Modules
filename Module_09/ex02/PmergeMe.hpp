#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
# include <set>
# include <cmath>

class PmergeMe {

private:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);
	
	static void check(std::vector<int> &v);
	static void print(std::vector<int> &v);
	static void fill_vector(char **argv, std::vector<int> &v);
	static void fill_pairs(std::vector<int> &v, std::vector<std::pair<int, int> > &pairs);
	static void sort_pairs(std::vector<std::pair<int, int> > &pairs);
	static void devide_to_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups);
	static void amount_of_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups);
	static void insert_in_sorted(std::vector<std::vector<int> > &groups, std::vector<int> &sorted);
	static void binary_insert(std::vector<int> &sorted, int num, int group_index);
	static void print_groups(std::vector<std::vector<int> > &groups);
	static void print_pairs(std::vector<std::pair<int, int> > &pairs);
	static void merge_sort(std::vector<std::pair<int, int> > &pairs, int left, int right);
	static void merge(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right);
	static void insert(std::vector<std::pair<int, int> > &pairs, std::vector<int> &new_v);
	static bool areVectorsEqual(const std::vector<int>& vector1, const std::vector<int>& vector2);

public:
	static bool sort(char **argv, int argc);
};

#endif