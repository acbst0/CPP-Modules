#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Just a pathetic intern created" << std::endl;
}

Intern::Intern(const Intern& ref)
{
	std::cout << "Just a pathetic intern created with copy" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Just a pathetic intern detroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& ref)
{
	return (*this);
}

AForm* Intern::makeForm(std::string& _form, std::string& _target)
{
	int len = _form.length();
	switch (len)
	{
	
	}
}