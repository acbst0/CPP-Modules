#include <iostream>

int	main(int ac, char **av)
{
	int	i;

	i = 1;

	while (i < ac)
	{
		std::cout << av[i - 1];
		i++;
	}
	return (0);
}