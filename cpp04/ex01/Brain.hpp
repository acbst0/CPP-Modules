#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string *ideas;
	public:
		Brain();
		Brain(const Brain& ref);
		~Brain();
		Brain& operator=(const Brain& ref);

		void setAllIdeas(std::string idea);
		void printNidea(int i);
};

#endif