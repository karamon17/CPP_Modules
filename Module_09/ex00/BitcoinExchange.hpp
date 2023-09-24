#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

class BitcoinExchange
{
private:
	static std::map<std::string, float> _database;

	BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

	static void pars_database();
	static void check_input(const std::string &filename);
	static void pars_input(const std::string &filename);
	static bool check_date(std::string &date);
	static bool check_value(std::string &value);
	static float get_result(std::string &date, std::string &value);

public:
	BitcoinExchange();
	~BitcoinExchange();
	static void run(const std::string &filename);
};

#endif