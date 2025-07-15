#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 25 sign grade, 5 exec grade" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm("Presidential Pardon Form", 25, 5), _target(ref._target)
{
	std::cout << this->getName() << " copy has been created with target ";
	std::cout << this->_target << " and 25 sign grade, 5 exec grade" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " has been destroyed with target ";
	std::cout << this->_target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this != &ref)
	{
		this->setisSigned(ref);
		this->_target = ref._target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 25 sign grade, 5 exec grade" << std::endl;
}

void PresidentialPardonForm::action() const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}