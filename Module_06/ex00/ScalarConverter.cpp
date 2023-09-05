#include "ScalarConverter.hpp"

int			ScalarConverter::_int = 0;
double		ScalarConverter::_double = 0;
float		ScalarConverter::_float = 0;
char		ScalarConverter::_char = 0;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

void ScalarConverter::convert(std::string const &input)
{	
	if (check_inf(input))
		return ;
	switch (detect_type(input))
	{
		case CHAR:
			printChar(input);
			break;
		case INT:
			printInt(input);
			break;
		case FLOAT:
			printFloat(input);
			break;	
		case DOUBLE:
			printDouble(input);
			break;	

		default:
			std::cout << "Syntax ERROR" << std::endl;
			break;
	}
}

int ScalarConverter::check_inf(std::string const &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		_double = strtod(input.c_str(), NULL);
		_float = static_cast<float>(_double);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		return (1);
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		_double = strtod(input.c_str(), NULL);
		_float = static_cast<float>(_double);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		return (1);
	}
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		_double = strtod(input.c_str(), NULL);
		_float = static_cast<float>(_double);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		return (1);
	}
	return (0);
}

int ScalarConverter::detect_type(std::string const &input)
{
	if (input.length() == 1 && !isdigit(input[0]))
	{
		_char = input[0];
		return (CHAR);
	}
	int i = 0;
	if (input[0] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if ((!isdigit(input[i]) && input[i] != 'f' && input[i] != '.') || (input[i] == 'f' && input[i + 1]))
			return (0);
	}
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			while (input[i] != 'f' && i < input.length())
				i++;
			if ((input[i] == 'f' && !input[i + 1]) || i == input.length())
			{
				_float = atof(input.c_str());
				return (FLOAT);
			}
		}
	}
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			int j = 0;
			while (i < input.length())
			{
				i++;
				j++;
			}
			if (i == input.length() && j > 6)
			{
				_double = atof(input.c_str());
				return (DOUBLE);
			}
			else
			{
				_float = atof(input.c_str());
				return (FLOAT);
			}
		}
	}
	i = 0;
	if (input[0] == '-')
		i++;
	for (; i < input.length(); i++)
	{
		if (i == input.length() - 1)
		{
			_double = atof(input.c_str());
			if (_double > INT_MAX || _double < INT_MIN)
				return (DOUBLE);
			_int = atoi(input.c_str());
			return (INT);
		}
	}
	return (0);
}

void ScalarConverter::printChar(std::string const &input)
{
	std::cout << "char: '" << _char << "'" << std::endl;
	_int = static_cast<int>(_char);
	std::cout << "int: " << _int << std::endl;
	_float = static_cast<float>(_char);
	std::cout << "float: " << _float << ".0f" << std::endl;
	_double = static_cast<double>(_char);
	std::cout << "double: " << _double << ".0" << std::endl;
}

void ScalarConverter::printInt(std::string const &input)
{
	if (_int >= -128 && _int <= 32)
		std::cout << "char: Non displayable" << std::endl;
	else if (_int >= 33 && _int <= 128)
	{
		_char = static_cast<char>(_int);
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << _int << std::endl;
	_float = static_cast<float>(_int);
	if (input.find('.') == std::string::npos)
	{
		std::cout << "float: " << _float << ".0f" << std::endl;
		_double = static_cast<double>(_int);
		std::cout << "double: " << _double << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << _float << "f" << std::endl;
		_double = static_cast<double>(_int);
		std::cout << "double: " << _double << std::endl;
	}
}

void ScalarConverter::printFloat(std::string const &input)
{
	_int = static_cast<int>(_float);
	if (_int >= -128 && _int <= 32)
		std::cout << "char: Non displayable" << std::endl;
	else if (_int >= 33 && _int <= 128)
	{
		_char = static_cast<char>(_int);
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << _int << std::endl;
	if (_float == static_cast<int>(_float))
	{
		std::cout << "float: " << _float << ".0f" << std::endl;
		_double = static_cast<double>(_float);
		std::cout << "double: " << _double << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << _float << "f" << std::endl;
		_double = static_cast<double>(_float);
		std::cout << "double: " << _double << std::endl;
	}
}

void ScalarConverter::printDouble(std::string const &input)
{
	if (_double > INT_MAX || _double < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		_int = static_cast<int>(_double);
		if (_int >= -128 && _int <= 32)
			std::cout << "char: Non displayable" << std::endl;
		else if (_int >= 33 && _int <= 128)
		{
			_char = static_cast<char>(_int);
			std::cout << "char: '" << _char << "'" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << _int << std::endl;
	}
	if (_float == static_cast<int>(_float))
	{
		_float = static_cast<float>(_double);
		std::cout << "float: " << _float << ".0f" << std::endl;
		std::cout << "double: " << _double << ".0" << std::endl;
	}
	else
	{
		_float = static_cast<float>(_double);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
}
