#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal has been created!" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	std::cout << "Wrong Animal has been created with copy constructor!" << std::endl;
	*this = ref;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal has been destroyed!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << "Wrong Animal copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Some wrong animal voices *" << std::endl;
}
