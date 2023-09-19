#ifndef PMERGEMELIST_HPP
# define PMERGEMELIST_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <set>
# include <cmath>

class PmergeMeList {

private:
	PmergeMeList();
	PmergeMeList(PmergeMeList const &src);
	~PmergeMeList();

	PmergeMeList &operator=(PmergeMeList const &rhs);
	
	static void check(std::list<int> &l);
	static void print(std::list<int> &l);
	static void fill_list(char **argv, std::list<int> &l);
	static void fill_pairs(std::list<int> &v, std::list<std::pair<int, int> > &pairs);
	static void sort_pairs(std::list<std::pair<int, int> > &pairs);
	static void devide_to_groups(std::list<std::pair<int, int> > &pairs, std::list<std::list<int> > &groups);
	static void amount_of_groups(std::list<std::pair<int, int> > &pairs, std::list<std::list<int> > &groups);
	static void insert_in_sorted(std::list<std::list<int> > &groups, std::list<int> &sorted);
	static void binary_insert(std::list<int> &sorted, int num, int group_index);
	static void print_groups(std::list<std::list<int> > &groups);
	static void print_pairs(std::list<std::pair<int, int> > &pairs);
	static void merge_sort(std::list<std::pair<int, int> > &pairs, int left, int right);
	static void merge(std::list<std::pair<int, int> > &pairs, int left, int mid, int right);
	static void insert(std::list<std::pair<int, int> > &pairs, std::list<int> &new_v);
	static bool areVectorsEqual(const std::set<int>& vector1, const std::set<int>& vector2);
	static void checker(std::list<int>& l, std::list<int>& sorted);

public:
	static void sort(char **argv, int argc);
};

#endif