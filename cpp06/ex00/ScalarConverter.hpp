#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define SPEC 5

class ScalarConverter
{
	private:

		static char _char;
		static int _int;
		static double _double;
		static float _float;

		static void printSpec(const std::string& ref);

		static bool is_special(const std::string& ref);
		static bool is_char(const std::string& ref);
		static bool is_int(const std::string& ref);
		static bool is_double(const std::string& ref);
		static size_t defineType(const std::string& ref);

		static double stod(const std::string& str);
		static int stoi(const std::string& str);
		static float stof(const std::string& str);
		static void printAll();

		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
	public:
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& ref);

		// The constructor(s) that i've added
		static void convert(const std::string& ref);
};



#endif