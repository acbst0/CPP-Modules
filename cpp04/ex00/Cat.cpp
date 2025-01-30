#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat has been created!" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat has been created with copy constructor!" << std::endl;
	*this = ref;
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOWWW" << std::endl;
}
