#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog has been created!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed!" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}