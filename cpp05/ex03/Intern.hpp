#ifndef INTER_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();
		Intern& operator=(const Intern& ref);
		AForm* makeForm(std::string& _form, std::string& _target);
		class WronTypeForm
		{
			public:

		};
		
};

#endif