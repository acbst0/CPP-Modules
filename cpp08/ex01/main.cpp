#include "Span.hpp"

int main()
{
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
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}