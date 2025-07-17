#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <exception>

# define INVALID 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define SPEC 5

class ScalarConverter
{
	private:

		char _char;
		int _int;
		double _double;
		float _float;

		void printSpec(const std::string& ref);

		bool is_special(const std::string& ref);
		bool is_char(const std::string& ref);
		bool is_int(const std::string& ref);
		bool is_double(const std::string& ref);
		size_t defineType(const std::string& ref);

		double stod(const std::string& str);
		int stoi(const std::string& str);
		float stof(const std::string& str);
		void printAll();

		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter& operator=(const ScalarConverter& ref);
		~ScalarConverter();

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	public:
		static void convert(const std::string& ref);
};



#endif