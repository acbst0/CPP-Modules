#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	(void)ref;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	return *this;
}

BitcoinExchange::BitcoinExchange(std::string str)
{
	std::ifstream _if;
}