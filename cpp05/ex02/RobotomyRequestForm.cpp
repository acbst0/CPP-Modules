#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 72 sign grade, 45 exec grade" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm("Robotomy Request Form", 72, 45), _target(ref._target)
{
	std::cout << this->getName() << " copy has been created with target ";
	std::cout << this->_target << " and 72 sign grade, 45 exec grade" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " has been destroyed with target ";
	std::cout << this->_target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this != &ref)
	{
		this->setisSigned(ref);
		this->_target = ref._target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 72 sign grade, 45 exec grade" << std::endl;
}

void RobotomyRequestForm::action() const
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }

    std::cout << "*VRRR! VRRR! VRRR!*" << std::endl;
    int i = std::rand();
    if (i % 2 != 0)
        throw RobotomyRequestForm::RobotomizedFailed();
    else
        std::cout << "Robotomized has been successful for target " << this->getTarget() << std::endl;
}

const char* RobotomyRequestForm::RobotomizedFailed::what() const throw()
{
	return ("Robotomy FAILED!");
}

const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}