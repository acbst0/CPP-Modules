#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No-name")
{
	std::cout << "Default Bureaucrat has been created!" << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name)
{
	this->_grade = ref.getGrade();
	std::cout << "Copy cosntructor has been called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name)
{
	std::cout << "A Bureaucrat named " << name << " has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("No-name")
{
	this->setGrade(grade);
	std::cout << "A Bureaucrat named " << this->_name << " with " << grade << " grade has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "A Bureaucrat named " << name << " with " << grade << " grade has been created!" << std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat named " << this->_name << " has been destroyed!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Bureaucrat assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->_grade = ref.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " has been assigned a new grade: " << this->_grade << std::endl;
}

void Bureaucrat::increment()
{
	if (this->_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
	std::cout << "Bureaucrat " << this->_name << " has been incremented to grade: " << this->_grade << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
	std::cout << "Bureaucrat " << this->_name << " has been decremented to grade: " << this->_grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cout << "Grade is too high!" << std::endl;
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cout << "Grade is too low!" << std::endl;
	return ("Grade is too low!");	
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "." << std::endl;
	return out;
}

void Bureaucrat::signForm(AForm& ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << this->_name << " signed " << ref.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign the " << ref.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}