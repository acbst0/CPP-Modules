#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter just 2 input :(" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}