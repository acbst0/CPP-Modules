#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal* j = new Dog();
		Animal* i = new Cat();

		std::cout << std::endl;

		std::cout << "Type Of Dog -> " << j->getType() << " " << std::endl;
		std::cout << "Type Of Cat -> " << i->getType() << " " << std::endl;

		std::cout << std::endl;

		std::cout << "Cat says : ";
		i->makeSound();
		std::cout << "Dog says : ";
		j->makeSound();

		std::cout << std::endl;
		
		delete i;
		delete j;
	}
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
	{
		const WrongAnimal *meta = new WrongAnimal;
		const WrongAnimal *cat = new WrongCat;

		std::cout << std::endl;

		std::cout << "Wrong Animal Type -> " << meta->getType() << std::endl;
		std::cout << "Wrong Cat Type-> " << cat->getType() << std::endl;

		std::cout << std::endl;

		std::cout << "Wrong Animal Says : ";
		meta->makeSound();
		std::cout << "Wrong Cat says : ";
		cat->makeSound();

		std::cout << std::endl;

		delete meta;
		delete cat;
	}
	return 0;
}