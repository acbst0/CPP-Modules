#include "ScalarConverter.hpp"

bool ScalarConverter::is_special(const std::string& ref)
{
	if (ref == "nan" || ref == "nanf" || ref == "+inf" || ref == "+inff" || ref == "-inf" || ref == "-inff")
		return true;
	return false;
}

bool ScalarConverter::is_char(const std::string& ref)
{
	if (ref.length() == 1 && !std::isdigit(ref[0]))
		return true;
	return false;
}

bool ScalarConverter::is_int(const std::string& ref)
{
    for (size_t i = 0; i < ref.length(); i++)
    {
        if (!std::isdigit(ref[i]))
        {
            if (i == 0 && ref[i] == '-')
            {
                
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool ScalarConverter::is_double(const std::string& ref)
{
	size_t dot_index = ref.find('.');
	size_t len = ref.length();

	for (size_t i = 0; i < len; i ++)
	{
		if (i == 0 && ref[i] == '-')
			;
		else if (i == dot_index)
			;
		else if (i == len - 1 && ref[i] == 'f')
			;
		else if (!std::isdigit(ref[i]))
			return false;
	}
	return true;
}

size_t ScalarConverter::defineType(const std::string& ref)
{
	if (ref.find('.') == std::string::npos)
	{
		if (ScalarConverter::is_special(ref) == true)
			return SPEC;
		if (ScalarConverter::is_char(ref) == true)
			return CHAR;
		if (ScalarConverter::is_int(ref) == true)
			return INT;
	}
	else
	{
		if (ScalarConverter::is_double(ref) == true)
		{
			if (ref[ref.length() - 1] == 'f')
				return FLOAT;
			else
				return DOUBLE;
		}
	}
	return INVALID;
}

int ScalarConverter::stoi(const std::string& str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;
    if (ss.fail() || !ss.eof()) // Check for conversion errors
        throw std::invalid_argument("Invalid integer format");
    return result;
}

float ScalarConverter::stof(const std::string& str)
{
    std::string modifiedStr = str;
    if (!modifiedStr.empty() && modifiedStr[modifiedStr.length() - 1] == 'f') // Check if the string ends with 'f'
        modifiedStr = modifiedStr.substr(0, modifiedStr.length() - 1);        // Remove the 'f' suffix

    std::stringstream ss(modifiedStr);
    float result;
    ss >> result;
    if (ss.fail() || !ss.eof()) // Check for conversion errors
        throw std::invalid_argument("Invalid float format");
    return result;
}

double ScalarConverter::stod(const std::string& str)
{
    std::stringstream ss(str);
    double result;
    ss >> result;
    if (ss.fail() || !ss.eof()) // Check for conversion errors
        throw std::invalid_argument("Invalid double format");
    return result;
}