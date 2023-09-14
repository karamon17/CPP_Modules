#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

class RPN {
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	static bool check_input(const std::string &arg);
	static void run(const std::string &arg);
};

#endif 