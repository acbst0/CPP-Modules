#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Dog* j = new Dog();
		Cat* i = new Cat();
		Dog* copyj = new Dog(*j);

		std::cout << std::endl;

		std::cout << "Type Of Dog -> " << j->getType() << " " << std::endl;
		std::cout << "Type Of Cat -> " << i->getType() << " " << std::endl;

		std::cout << std::endl;

		std::cout << "Cat says : ";
		i->makeSound();
		std::cout << "Dog says : ";
		j->makeSound();

		std::cout << std::endl;

		i->setCatIdea("Fish Fish Fish");
		std::cout << "What is cat thinking?" << std::endl;
		i->printIdea(5);

		std::cout << std::endl;

		j->setDogIdea("Game Game Game");
		std::cout << "What is Dog thinking?" << std::endl;
		j->printNidea(5);

		std::cout << std::endl;

		std::cout << "Original Dog Brain :" << std::endl;
		j->printBrainAddress();
		std::cout << "Copy Dog Brain     :" << std::endl;
		copyj->printBrainAddress();
		
		std::cout << std::endl;

		delete copyj;
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