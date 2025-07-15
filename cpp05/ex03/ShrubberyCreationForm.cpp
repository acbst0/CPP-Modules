#include "ShrubberyCreationForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubberry Creation Form", 145, 137), _target("default")
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 145 sign grade, 137 exec grade" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref), _target(ref._target)
{
	std::cout << this->getName() << " copy has been created with target ";
	std::cout << this->_target << " and 145 sign grade, 137 exec grade" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName() << " has been destroyed with target ";
	std::cout << this->_target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
	{
		this->setisSigned(ref);
		this->_target = ref._target;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubberry Creation Form",145, 137), _target(target)
{
	std::cout << this->getName() << " has been created with target ";
	std::cout << this->_target << " and 145 sign grade, 137 exec grade" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

const char* ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return "There is a problem about file creation!";
}

void ShrubberyCreationForm::action() const
{
	std::ofstream out((this->getTarget() + std::string("_shrubbery")).c_str());

	if (out)
	{
		out << "          &&& &&  & &&        " << std::endl;
		out << "      && &\\/&\\|& ()|/ @, &&   " << std::endl;
		out << "      &\\/(/&/&||/& /_/)_&/_&  " << std::endl;
		out << "   &() &\\/&|()|/&\\/ /%/ & ()  " << std::endl;
		out << "  &_\\_&&_\\ |& |&&/&__%_/_& && " << std::endl;
		out << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		out << " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl;
		out << "     &&     \\|||              " << std::endl;
		out << "             |||              " << std::endl;
		out << "             |||              " << std::endl;
		out << "             |||              " << std::endl;
		out << "       , -=-~  .-^- _         " << std::endl;

		out.close();
		std::cout << this->getTarget() + std::string("_shrubbery") << " has been created!" << std::endl;
	}
	else
		throw ShrubberyCreationForm::OpenFileExeption();
}