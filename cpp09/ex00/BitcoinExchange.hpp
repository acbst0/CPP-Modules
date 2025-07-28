#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dates;
		std::ifstream target;
		std::ifstream db;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);
		
	public:
		BitcoinExchange(std::string _target);
		~BitcoinExchange();

		void checkDB();
		void addAllToMap();
		void processInput();

		class FileError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DBError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::string trim(const std::string& str);
bool isValidDate(const std::string& date);

#endif