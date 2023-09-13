#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;
	std::forward_list<int> fl;
	std::array<int, 5> a;
	std::deque<int> d;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
		l.push_back(i);
		fl.push_front(i);
		a[i] = i;
		d.push_back(i);
	}

	try
	{
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(l, 3) << std::endl;
		std::cout << *easyfind(fl, 3) << std::endl;
		std::cout << *easyfind(a, 3) << std::endl;
		std::cout << *easyfind(d, 3) << std::endl;
		std::cout << *easyfind(v, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}