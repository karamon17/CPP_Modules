#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_database;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

void BitcoinExchange::pars_database()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Could not open file.");
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string exchange_rate;
		std::getline(ss, date, ',');
		std::getline(ss, exchange_rate, '\n');
		_database[date] = static_cast<float>(std::atof(exchange_rate.c_str()));
	}
	file.close();
}

void BitcoinExchange::check_input(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file.");
	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		file.close();
		throw std::runtime_error("Invalid file format: incorrect first line.");
	}
	file.close();
}

bool BitcoinExchange::check_date(std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	for (size_t i = 0; i < year.length(); ++i) {
        if (!isdigit(year[i])) {
            return false;
        }
    }
	for (size_t i = 0; i < month.length(); ++i) {
		if (!isdigit(month[i])) {
			return false;
		}
	}
	for (size_t i = 0; i < day.length(); ++i) {
		if (!isdigit(day[i])) {
			return false;
		}
	}
	int year_int = std::atoi(year.c_str());
	int month_int = std::atoi(month.c_str());
	int day_int = std::atoi(day.c_str());
	if (year_int < 0)
		return (0);
	if (month_int < 1 || month_int > 12)
		return (0);
	if (day_int < 1 || day_int > 31)
		return (0);
	if (month_int == 2 && day_int > 29)
		return (0);
	if ((month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11) && day_int > 30)
		return (0);
	if (((year_int % 100 == 0 && year_int % 400 != 0) || year_int % 4 != 0) && month_int == 2 && day_int == 29)
		return (0);
	return (1);
}

bool BitcoinExchange::check_value(std::string &value)
{
	if (value[0] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}	
	for (size_t i = 0; i < value.length(); ++i) {
		if (!isdigit(value[i]) && value[i] != '.') {
			return false;
		}
	}
	if (std::count(value.begin(), value.end(), '.') > 1 || value[0] == '.' || value[value.size() - 1] == '.')
		return (0);
	float value_float = static_cast<float>(std::atof(value.c_str()));
	if (value_float > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

float BitcoinExchange::get_result(std::string &date, std::string &value)
{
	float value_float = static_cast<float>(std::atof(value.c_str()));
	if (_database.count(date))
	{
		float exchange_rate = _database[date];
		return (value_float * exchange_rate);
	}
	std::map<std::string, float>::const_iterator iter = _database.begin();
	for(; iter != _database.end(); iter++)
    {
		if (iter->first > date && iter != _database.begin())
		{
			iter--;
	 		return (value_float * iter->second);
		}
		else if (iter->first > date && iter == _database.begin())
			return (0);
    }
	std::map<std::string, float>::reverse_iterator rit = _database.rbegin();
	return (value_float * rit->second);
}

void BitcoinExchange::pars_input(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(" | ");
		if (pos != std::string::npos) 
		{
			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 3);
			if (!check_date(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			 if (!check_value(value))
			 	continue;
			float res = get_result(date, value);
			std::cout << date << " => " << value << " = " << res << std::endl;
		} 
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
    	}
	}
}

void BitcoinExchange::run(const std::string &filename)
{
	pars_database();
	check_input(filename);
	pars_input(filename);
}