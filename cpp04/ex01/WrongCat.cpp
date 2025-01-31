#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Wrong Cat has been created!" << std::endl;
	this->type =  "WrongCat";
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
	std::cout << "Wrong Cat has been created with copy constructor!" << std::endl;
	*this = ref;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat has been destroyed!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	std::cout << "Wrong Cat copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Cat sound!" << std::endl;
}