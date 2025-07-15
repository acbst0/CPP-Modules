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

const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::action() const
{
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->getTarget() << "!" << std::endl;
    }
}