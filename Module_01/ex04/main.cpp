#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Wrong number of arguments." << std::endl;
		return 1;
	}
	Replacer replase(argv[1], argv[2], argv[3]);
	replase.replace();
	replase.create_new_file();
	return 0;
}