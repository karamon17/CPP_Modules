#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cout << "ERROR in arguments count" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}