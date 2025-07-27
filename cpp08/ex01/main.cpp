#include "Span.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "          Standart Tests        " << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	try
	{
		std::vector<int> test;
		test.push_back(6);
		test.push_back(2);
		test.push_back(4);
		test.push_back(5);
		sp.addNumbers(test.begin(), test.end());
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(11);
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "      10.000 Elements Test      " << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	Span big(10000);
	for (int i = 0; i < 10000; ++i)
		big.addNumber(rand());
	std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big.longestSpan() << std::endl;
	return 0;
}