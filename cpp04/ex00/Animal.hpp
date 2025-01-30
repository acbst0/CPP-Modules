#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& ref);
		virtual ~Animal();
		Animal& operator=(const Animal& ref);
		std::string getType() const;
		virtual void makeSound() const;
};

#endif
