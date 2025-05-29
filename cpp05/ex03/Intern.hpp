#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();
		Intern& operator=(const Intern& ref);
		AForm* makeForm(const std::string& _form, const std::string& _target);
};

#endif