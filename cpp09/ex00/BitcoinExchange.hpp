#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dates;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& ref);
	public:
		BitcoinExchange(std::string str);
};

#endif