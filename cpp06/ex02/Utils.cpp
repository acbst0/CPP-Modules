#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base* generate(void)
{
	static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    int i = std::rand() % 3;
    
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base* ptr)
{
	A* Aptr = dynamic_cast<A*>(ptr);
	B* Bptr = dynamic_cast<B*>(ptr);
	C* Cptr = dynamic_cast<C*>(ptr);

	if (Aptr != NULL)
		std::cout << "This is A class" << std::endl;
	else if (Bptr != NULL)
		std::cout << "This is B class" << std::endl;
	else if (Cptr != NULL)
		std::cout << "This is C class" << std::endl;
}

void identify(Base& ptr)
{
	try
	{
		A& Aref = dynamic_cast<A&>(ptr);
		(void)Aref;
		std::cout << "This is A class" << std::endl;
		return ;
	}
	catch (std::exception& e)
	{}
	try
	{
		B& Bref = dynamic_cast<B&>(ptr);
		(void)Bref;
		std::cout << "This is B class" << std::endl;
		return ;
	}
	catch (std::exception& e)
	{}
	try
	{
		C& Cref = dynamic_cast<C&>(ptr);
		(void)Cref;
		std::cout << "This is C class" << std::endl;
	}
	catch (std::exception& e)
	{}
}