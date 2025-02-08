#include "Bureucrat.hpp"

Bureucrat::Bureucrat() : _name("No-name")
{
	std::cout << "Default Bureucrat has been created!" << std::endl;
	this->setGrade(150);
}

Bureucrat::Bureucrat(const Bureucrat& ref) : _name(ref._name)
{
	this->_grade = ref.getGrade();
	std::cout << "Copy cosntructor has been called!" << std::endl;
}

Bureucrat::Bureucrat(const std::string name) : _name(name)
{
	std::cout << "A Bureucrat named " << name << " has been created!" << std::endl;
}

Bureucrat::Bureucrat(size_t grade) : _name("No-name")
{
	this->setGrade(grade);
	std::cout << "A Bureucrat named " << this->_name << " with " << grade << " grade has been created!" << std::endl;
}

Bureucrat::Bureucrat(const std::string name, size_t grade) : _name(name)
{
	this->_grade = grade;
	std::cout << "A Bureucrat named " << name << " with " << grade << " grade has been created!" << std::endl;
}

Bureucrat::~Bureucrat()
{
	std::cout << "Bureucrat named " << this->_name << " has been destroyed!" << std::endl
}

Bureucrat& Bureucrat::operator=(const Bureucrat& ref)
{
	std::cout << "Bureucrat assigment operator has been called!" << std::endl;
	if (this != &ref)
	{
		
	}
}

const std::string Bureucrat::getName()
{
	return this->_name;
}

size_t Bureucrat::getGrade()
{
	
}

void Bureucrat::setGrade(size_t grade)
{

}

void Bureucrat::increment()
{

}

void Bureucrat::decrement()
{

}

const char* Bureucrat::GradeTooHighException::what() const throw()
{

}

const char* Bureucrat::GradeTooLowException::what() const throw()
{
	
}

std::ostream& operator<<(std::ostream& out, Bureucrat& ref)
{

}