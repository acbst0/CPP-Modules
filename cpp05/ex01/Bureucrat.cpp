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

Bureucrat::Bureucrat(int grade) : _name("No-name")
{
	this->setGrade(grade);
	std::cout << "A Bureucrat named " << this->_name << " with " << grade << " grade has been created!" << std::endl;
}

Bureucrat::Bureucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "A Bureucrat named " << name << " with " << grade << " grade has been created!" << std::endl;
	if (grade < 1)
	{
		throw Bureucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureucrat::~Bureucrat()
{
	std::cout << "Bureucrat named " << this->_name << " has been destroyed!" << std::endl;
}

Bureucrat& Bureucrat::operator=(const Bureucrat& ref)
{
	std::cout << "Bureucrat assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->_grade = ref.getGrade();
	return (*this);
}

const std::string Bureucrat::getName()
{
	return (this->_name);
}

int Bureucrat::getGrade() const
{
	return (this->_grade);
}

void Bureucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw Bureucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureucrat::GradeTooLowException();
	}
	this->_grade = grade;
	std::cout << "Bureucrat " << this->_name << " has been assigned a new grade: " << this->_grade << std::endl;
}

void Bureucrat::increment()
{
	if (this->_grade == 1)
	{
		throw Bureucrat::GradeTooHighException();
	}
	this->_grade--;
	std::cout << "Bureucrat " << this->_name << " has been incremented to grade: " << this->_grade << std::endl;
}

void Bureucrat::decrement()
{
	if (this->_grade == 150)
	{
		throw Bureucrat::GradeTooLowException();
	}
	this->_grade++;
	std::cout << "Bureucrat " << this->_name << " has been decremented to grade: " << this->_grade << std::endl;
}

const char* Bureucrat::GradeTooHighException::what() const throw()
{
	std::cout << "Grade is too high!" << std::endl;
	return ("Grade is too high!");
}

const char* Bureucrat::GradeTooLowException::what() const throw()
{
	std::cout << "Grade is too low!" << std::endl;
	return ("Grade is too low!");	
}

std::ostream& operator<<(std::ostream& out, Bureucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return out;
}

void Bureucrat::signForm(Form& ref)
{
	try
	{
		ref.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << "couldn’t sign the " << ref.getName() << " because " << e.what() << '\n';
	}
	std::cout << this->_name << " signed " << ref.getName();
}