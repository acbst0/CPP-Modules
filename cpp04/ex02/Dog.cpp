#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog has been created!" << std::endl;
	this->type = "Dog";
	this->br = new Brain();
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
	std::cout << "Dog has been created with copy constructor!" << std::endl;
	this->br = new Brain(*ref.br);
	this->type = ref.type;
}

Dog::~Dog()
{
	delete this->br;
	std::cout << "Dog has been destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog copy assignment operator has been called!" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
		delete this->br;
		this->br = new Brain(*ref.br);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

void Dog::setDogIdea(std::string str)
{
	br->setAllIdeas(str);
}

void Dog::printNidea(int i)
{
	this->br->printNidea(i);
}

void Dog::printBrainAddress()
{
	std::cout << this->br << std::endl;
}