#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define SPEC 5

class ScalarConverter
{
	private:

		static void printSpec(const std::string& ref);
		// Static Convert Funcs
		static void convertChar(const std::string& ref);
		static void convertInt(const std::string& ref);
		static void convertFloat(const std::string& ref);
		static void convertDouble(const std::string& ref);

		static bool is_special(const std::string& ref);
		static bool is_char(const std::string& ref);
		static bool is_int(const std::string& ref);
		static bool is_double(const std::string& ref);
		static size_t defineType(const std::string& ref);

	public:

		// Othadox Conical Funcs
		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& ref);

		// The constructor(s) that i've added
		static void convert(const std::string& ref);
};

#endif