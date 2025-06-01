#include "ScalarConverter.hpp"

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
	return (*this);
}

void ScalarConverter::printSpec(const std::string& ref)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convertChar(const std::string& ref)
{
	size_t type = defineType(ref);
}

void ScalarConverter::convertInt(const std::string& ref)
{
	try
	{
		int i = std::stoi(ref);
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::convertFloat(const std::string& ref)
{

}

void ScalarConverter::convertDouble(const std::string& ref)
{

}

void ScalarConverter::convert(const std::string& ref)
{
	size_t type = ScalarConverter::defineType(ref);
	if (type == SPEC)
		printSpec(ref);
	else
	{
		for (int i = 1; i < 6; i++)
		{
			
		}
	}
}