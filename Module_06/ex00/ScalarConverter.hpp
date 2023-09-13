#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

		enum Type
		{
			CHAR = 1,
			INT,
			FLOAT,
			DOUBLE
		};

		static char _char;
		static int _int;
		static float _float;
		static double _double;

		static void printChar(std::string const &input);
		static void printInt(std::string const &input);
		static void printFloat(std::string const &input);
		static void printDouble(std::string const &input);

		static int detect_type(std::string const &input);
		static int check_inf(std::string const &input);

	public:
		static void convert(std::string const &input);
};

#endif