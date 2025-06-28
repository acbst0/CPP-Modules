#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* ptr);
void identify(Base& ptr);

#endif