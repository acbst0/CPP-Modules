#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat has been created!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed!" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

void Cat::makeSound() const
{
	std::cout << "MEOWWW" << std::endl;
}
