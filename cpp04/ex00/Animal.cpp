#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Undefined";
	std::cout << "Animal has been created!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed!" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Just animal voice" << std::endl;
}
