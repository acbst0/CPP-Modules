#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>

class Bureucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureucrat();
	Bureucrat(const Bureucrat& ref);
	~Bureucrat();
	Bureucrat& operator=(const Bureucrat& ref);
};


#endif