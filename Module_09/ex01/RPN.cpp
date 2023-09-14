#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

bool RPN::check_input(const std::string &arg)
{
	std::stringstream ss;
    ss << arg;
	std::string token;
	while (ss)
	{
		ss >> token;
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
			continue;
		if (token.length() > 1)
			return (false);
		if (token[0] >= '0' && token[0] <= '9')
			continue;
		return (false);
	}
	return (true);
}

void RPN::run(const std::string &arg)
{
	if (!check_input(arg))
		throw std::logic_error("Error");
	else
	{
		std::stack<int> stack;
		std::string token;
		for (size_t i = 0; i < arg.size(); i++)
		{
			if (arg[i] == ' ')
				continue;
			if (isdigit(arg[i]))
				stack.push(arg[i] - '0');
			else if (stack.empty())
				throw std::logic_error("Error");
			else if (arg[i] != ' ')
			{
				int a = stack.top();
				stack.pop();
				if (stack.empty())
					throw std::logic_error("Error");
				int b = stack.top();
				stack.pop();
				long long check_overflow;
				if (arg[i] == '+')
				{
					check_overflow = static_cast<long long>(a) + static_cast<long long>(b);
					if (check_overflow > INT_MAX || check_overflow < INT_MIN)
						throw std::logic_error("Error overflow");
					stack.push(a + b);
				}
				else if (arg[i] == '-')
				{
					check_overflow = static_cast<long long>(b) - static_cast<long long>(a);
					if (check_overflow > INT_MAX || check_overflow < INT_MIN)
						throw std::logic_error("Error overflow");
					stack.push(b - a);
				}
				else if (arg[i] == '*')
				{
					check_overflow = static_cast<long long>(a) * static_cast<long long>(b);
					if (check_overflow > INT_MAX || check_overflow < INT_MIN)
						throw std::logic_error("Error overflow");
					stack.push(a * b);
				}
				else if (arg[i] == '/')
				{
					if (a == 0)
						throw std::logic_error("Sorry, can't divide by 0");
					stack.push(b / a);
				}
				else if (arg[i] == '%')
					stack.push(b % a);
			}
		}
		if (stack.size() != 1)
			throw std::logic_error("Error");
		else
			std::cout << stack.top() << std::endl;
	}
}