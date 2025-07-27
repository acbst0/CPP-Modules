#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	(void)ref;
}

BitcoinExchange::~BitcoinExchange()
{
	if (this->target)
		this->target.close();
    if (this->db)
        this->db.close();
	
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	return *this;
}

BitcoinExchange::BitcoinExchange(std::string _target)
{
	this->target = std::ifstream(_target);
	this->db = std::ifstream("data.csv");
	
	if (!this->target)
		throw FileError();
    if (!this->db)
        throw DBError();
}

void BitcoinExchange::checkDB()
{
	std::string line;
	std::getline(db, line);

	if (line != "date,exchange_rate")
		throw DBError(); // başlık hatalı

	int line_num = 1;
	while (std::getline(db, line))
	{
		++line_num;
		std::stringstream ss(line);
		std::string date, valueStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: Malformed line at " << line_num << ": " << line << std::endl;
			throw DBError();
		}

		date = trim(date);
		valueStr = trim(valueStr);

		// Tarih kontrolü
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date at line " << line_num << ": " << date << std::endl;
			throw DBError();
		}

		// Sayısal kontrol
		char* end;
		double val = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0' || val < 0)
		{
			std::cerr << "Error: Invalid number at line " << line_num << ": " << valueStr << std::endl;
			throw DBError();
		}
	}
	// Kontrol sonrası dosya başa alınmalı:
	db.clear();
	db.seekg(0, std::ios::beg);
}

void BitcoinExchange::addAllToMap()
{
    std::string line;

    std::getline(db, line);

    while (std::getline(db, line))
    {
        std::stringstream ss(line);
        std::string date, priceStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, priceStr))
            continue;

        date = trim(date);
        priceStr = trim(priceStr);

        float price = std::atof(priceStr.c_str());
        this->_dates[date] = price;
    }
}


const char* BitcoinExchange::FileError::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BitcoinExchange::DBError::what() const throw()
{
	return ("Error: could not open DB file or wrong type!");
}

const char* BitcoinExchange::TooLargeNum::what() const throw()
{
	return ("Error: too large a number.");
}

const char* BitcoinExchange::NotPositiveNum::what() const throw()
{
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::BadInput::what() const throw()
{
	return ("Error: bad input => ");
}

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

bool isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
		return false;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Daha fazla kontrol (örneğin Şubat 30, vs.) istersen ekleyebilirsin
	return true;
}