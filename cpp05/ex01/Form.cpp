#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("no-name"), required2sign(150), required2exec(150)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created with default constructor!" << std::endl;
}

Form::Form(const Form& ref) : _name(ref._name), required2sign(ref.required2sign), required2exec(ref.required2exec)
{
	this->isSigned = ref.isSigned;
	std::cout << "A form named " << this->_name << " has been created with copy constructor!" << std::endl;
}

Form::~Form()
{
	std::cout << "A form named " << this->_name << " has been destroyed!" << std::endl;
}

Form& Form::operator=(const Form& ref)
{
	if (this != &ref)
	{
		this->isSigned = ref.isSigned;
	}
	return *this;
}

Form::Form(const std::string& name, const int r2s, const int r2e) : _name(name), required2sign(r2s), required2exec(r2e)
{
	if (r2e < 1 || r2s < 1)
		throw GradeTooHighException();
	else if (r2e > 150 || r2s > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

Form::Form(const int r2s, const int r2e) : _name("no-name"), required2sign(r2s), required2exec(r2e)
{
	if (r2e < 1 || r2s < 1)
		throw GradeTooHighException();
	else if (r2e > 150 || r2s > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

Form::Form(const std::string& name) : _name(name), required2sign(75), required2exec(75)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

void Form::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() > this->required2sign)
	{
		throw Form::GradeTooLowException();
	}
	if (ref.getGrade() < 1)
	{
		throw Form::GradeTooHighException();
	}
	this->isSigned = true;
}

const std::string Form::getName() 
{
	return this->_name;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

int Form::r2s() const
{
	return this->required2sign;
}

int Form::r2e() const
{
	return this->required2exec;
}

std::ostream& operator<<(std::ostream& out, Form& ref)
{
	out << ref.getName() << ", forms required for sign " << ref.r2s() << " and required for execution " << ref.r2e() << "." << std::endl;
	return out;
}
