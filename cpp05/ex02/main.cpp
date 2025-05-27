#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm test("Hey");
	Bureaucrat one("Jack", 11);

	std::cout << std::endl;

	one.executeForm(test);

	std::cout << std::endl;

	one.signForm(test);
	one.executeForm(test);

	std::cout << std::endl;
	return 0;
}
