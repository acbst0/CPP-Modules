#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal has been created!" << std::endl;
	this->type = "Undefined";
}

Animal::Animal(const Animal& ref)
{
	std::cout << "Animal has been created with copy constructor!" << std::endl;
	*this = ref;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed!" << std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << "Animal copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* Just animal voice *" << std::endl;
}
