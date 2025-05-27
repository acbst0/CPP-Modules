#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm test("Hey");
	RobotomyRequestForm karen("Karen");
	PresidentialPardonForm MainChar("Gerald");
	Bureaucrat one("Jack", 20);
	Bureaucrat two("John", 1);

	std::cout << std::endl;

	one.executeForm(test);

	std::cout << std::endl;

	one.signForm(test);
	one.executeForm(test);

	std::cout << std::endl;

	one.signForm(karen);
	one.executeForm(karen);

	std::cout << std::endl;

	one.signForm(MainChar);
	one.executeForm(MainChar);
	two.executeForm(MainChar);

	std::cout << std::endl;
	return 0;
}
