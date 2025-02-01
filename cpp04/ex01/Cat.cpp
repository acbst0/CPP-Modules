#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat has been created!" << std::endl;
	this->type = "Cat";
	this->br = new Brain();
}

Cat::Cat(const Cat& ref) : Animal(ref)
{
	std::cout << "Cat has been created with copy constructor!" << std::endl;
	this->br = new Brain(*ref.br);
	this->type = ref.type;
}

Cat::~Cat()
{
	delete this->br;
	std::cout << "Cat has been destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assigment operator has been called!" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
		delete this->br;
		this->br = new Brain(*ref.br);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOWWW" << std::endl;
}

void Cat::setCatIdea(std::string str)
{
	br->setAllIdeas(str);
}

void Cat::printIdea(int i)
{
	this->br->printNidea(i);
}

void Cat::printBrainAddress()
{
	std::cout << this->br << std::endl;
}