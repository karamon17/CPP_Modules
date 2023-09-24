#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong amount of arguments" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange::run(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
		return 1;
    }
    return 0;
}