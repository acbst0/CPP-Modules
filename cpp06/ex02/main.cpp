# include "Base.hpp"

int main()
{
	Base* obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;

	Base* obj2 = generate();
	identify(obj2);
	identify(*obj2);
	delete obj2;
}