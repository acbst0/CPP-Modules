#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been created!" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain has been created with copy consturctor!" << std::endl;
	*this = ref;
}

Brain::~Brain()
{
	delete[] this->ideas;
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << "Brain's copy assigment operator has been called!" << std::endl;
	if (this != &ref)
		this->ideas = ref.ideas;
	return *this;
}

void Brain::setAllIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

std::string* Brain::getAllIdeas()
{
	return this->ideas;
}
