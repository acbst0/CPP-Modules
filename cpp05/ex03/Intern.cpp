#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Just a pathetic intern created" << std::endl;
}

Intern::Intern(const Intern& ref)
{
	(void) ref;
	std::cout << "Just a pathetic intern created with copy" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Just a pathetic intern detroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& ref)
{
	(void) ref;
	return (*this);
}

AForm* Intern::makeForm(const std::string& _form, const std::string& _target)
{
	std::string _names[] = {"Shrubberry Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	int i = 0;

	for (; i < 3 && _form != _names[i] && i < 3; i++) {}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << _form << std::endl;
			return new ShrubberyCreationForm(_target);
		case 1:
			std::cout << "Intern creates " << _form << std::endl;
			return new RobotomyRequestForm(_target);
		case 2:
			std::cout << "Intern creates " << _form << std::endl;
			return new PresidentialPardonForm(_target);
		default:
			std::cout << "There is not a form type as " << _form << std::endl;
			return NULL;
	}
	return NULL;
}