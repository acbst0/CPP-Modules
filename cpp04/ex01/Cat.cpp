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
	*this = ref;
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed!" << std::endl;
	delete this->br;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat copy assigment operator has been called!" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
		this->br = ref.br;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOWWW" << std::endl;
}

void Cat::setCatIdea(const std::string& str)
{
	br->setAllIdeas(str);
}

void Cat::printIdea(int i)
{
	this->br->printNidea(i);
}