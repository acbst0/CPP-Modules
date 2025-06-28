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

/* 
Static cast doğru bir dönüşüm olduğunu bildiğimizde kullanılır
Hata varsa program çöker.

Dynamic Cast ise bir bak bakalım dönüşüyor mu der?
Sadece virtual fonksiyonu olan claslarda çalışır.
Hata varsa nullptr döner çökmez

Reinterpret Cast ise bir şeyi başka bir şey gibi gözükmeye zorlar.
Kullanımı nadir ve risklidir
*/

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