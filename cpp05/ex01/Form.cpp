#include "Form.hpp"

Form::Form() : _name("no-name"), required2exec(150), required2sign(150)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created with default constructor!" << std::endl;
}

Form::Form(const Form& ref) : _name(ref._name), required2exec(ref.required2exec), required2sign(ref.required2sign)
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
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

Form::Form(const int r2s, const int r2e) : _name("no-name"), required2sign(r2s), required2exec(r2e)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

void Form::beSigned(Bureucrat& ref)
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