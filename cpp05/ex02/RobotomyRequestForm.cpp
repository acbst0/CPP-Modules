#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm("Robotomy Request Form", 72, 45), _target(ref._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{

}

void RobotomyRequestForm::action() const
{
	
}

const char* RobotomyRequestForm::RobotomizedFailed::what() const throw()
{

}