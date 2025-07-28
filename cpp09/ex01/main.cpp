#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "You shoul have to use like " << std::endl;
		std::cerr << "./RPN ''1 1 +''" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
