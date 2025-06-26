#include "ScalarConverter.hpp"

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	(void)ref;
	return (*this);
}

void ScalarConverter::printSpec(const std::string& ref)
{
	if (ref == "nan" || ref == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (ref == "+inf" || ref == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (ref == "-inf" || ref == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::printAll()
{
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	size_t t = ScalarConverter::defineType(str);
	if (t == SPEC)
	{
		printSpec(str);
		return ;
	}
	else if (t == CHAR)
	{
		_char = str[0];
		_int = static_cast<int>(_char);
		_double = static_cast<double>(_char);
		_float = static_cast<float>(_char);
	}
	else if (t == INT)
	{
		_int = ScalarConverter::stoi(str);
		_char = static_cast<char>(_int);
		_double = static_cast<double>(_int);
		_float = static_cast<float>(_int);
	}
	else if (t == FLOAT)
	{
		_float = ScalarConverter::stof(str);
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	else if (t == DOUBLE)
	{
		_double = ScalarConverter::stod(str);
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	printAll();
}