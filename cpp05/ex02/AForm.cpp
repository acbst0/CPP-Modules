#include "AForm.hpp"
#include "Bureucrat.hpp"

AForm::AForm() : _name("no-name"), required2sign(150), required2exec(150)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created with default constructor!" << std::endl;
}

AForm::AForm(const AForm& ref) : _name(ref._name), required2sign(ref.required2sign), required2exec(ref.required2exec)
{
	this->isSigned = ref.isSigned;
	std::cout << "A form named " << this->_name << " has been created with copy constructor!" << std::endl;
}

AForm::~AForm()
{
	std::cout << "A form named " << this->_name << " has been destroyed!" << std::endl;
}

AForm& AForm::operator=(const AForm& ref)
{
	if (this != &ref)
	{
		this->isSigned = ref.isSigned;
	}
	return *this;
}

AForm::AForm(const std::string& name, const int r2s, const int r2e) : _name(name), required2sign(r2s), required2exec(r2e)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

AForm::AForm(const int r2s, const int r2e) : _name("no-name"), required2sign(r2s), required2exec(r2e)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

AForm::AForm(const std::string& name) : _name(name), required2exec(75), required2sign(75)
{
	this->isSigned = false;
	std::cout << "A form named " << this->_name << " has been created!" << std::endl;
}

void AForm::beSigned(const Bureucrat& ref)
{
	if (ref.getGrade() > this->required2sign)
	{
		throw AForm::GradeTooLowException();
	}
	if (ref.getGrade() < 1)
	{
		throw AForm::GradeTooHighException();
	}
	this->isSigned = true;
}

const std::string AForm::getName()
{
	return this->_name;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

int AForm::r2s()
{
	return this->required2sign;
}

int AForm::r2e()
{
	return this->required2exec;
}

std::ostream& operator<<(std::ostream& out, AForm& ref)
{
	out << ref.getName() << ", forms required for sign " << ref.r2s() << " and required for execution " << ref.r2e() << "." << std::endl;
	return out;
}