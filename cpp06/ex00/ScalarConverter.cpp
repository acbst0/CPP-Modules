#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _char(0), _int(0), _double(0.0), _float(0.0f)
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
	if (this != &ref)
	{
		this->_char = ref._char;
		this->_int = ref._int;
		this->_float = ref._float;
		this->_double = ref._double;
	}
	return (*this);
}

const char* ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid input");
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
	if (_char < 32 || _char > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	ScalarConverter converter;
	
	size_t t = converter.defineType(str);
	if (t == SPEC)
	{
		converter.printSpec(str);
		return;
	}
	else if (t == CHAR)
	{
		converter._char = str[0];
		converter._int = static_cast<int>(converter._char);
		converter._double = static_cast<double>(converter._char);
		converter._float = static_cast<float>(converter._char);
	}
	else if (t == INT)
	{
		converter._int = converter.stoi(str);
		converter._char = static_cast<char>(converter._int);
		converter._double = static_cast<double>(converter._int);
		converter._float = static_cast<float>(converter._int);
	}
	else if (t == FLOAT)
	{
		converter._float = converter.stof(str);
		converter._char = static_cast<char>(converter._float);
		converter._int = static_cast<int>(converter._float);
		converter._double = static_cast<double>(converter._float);
	}
	else if (t == DOUBLE)
	{
		converter._double = converter.stod(str);
		converter._char = static_cast<char>(converter._double);
		converter._int = static_cast<int>(converter._double);
		converter._float = static_cast<float>(converter._double);
	}
	else
	{
		throw InvalidInputException();
	}
	converter.printAll();
}