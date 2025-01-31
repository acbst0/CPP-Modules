#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog has been created!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	std::cout << "Dog has been created with copy constructor!" << std::endl;
	*this = ref;
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}