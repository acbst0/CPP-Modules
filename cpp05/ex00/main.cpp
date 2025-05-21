#include "Bureucrat.hpp"

int main()
{
	Bureucrat a("John", 1);
	Bureucrat b("Doe", 150);
	Bureucrat c("Smith", 75);

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	std::cout << a;
	std::cout << b;
	std::cout << c;

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	try
	{
		a.increment();
		std::cout << "After incrementing grade: " << a.getName() << " has grade " << a.getGrade() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		b.decrement();
		std::cout << "After decrementing grade: " << b.getName() << " has grade " << b.getGrade() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		c.increment();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	std::cout << a;
	std::cout << b;
	std::cout << c;

	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;

	return 0;
}