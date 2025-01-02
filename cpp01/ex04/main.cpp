/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:13 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 12:27:14 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static std::string filename(const char *av)
{
    std::string file;

    for (int i = 0; av[i]; ++i) {
        if (av[i] == '.')
            break;
        file += av[i];
    }
    return file;
}


static int	change(std::string str, char **av)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((filename(av[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int main(int ac, char **av)
{
	std::ifstream	file;
	std::string		str;
	char			c;

	if (ac != 4)
	{
		std::cout << "Invalid count of arguments!" << std::endl;
		return 1;
	}
	file.open(av[1]);
	if(file.fail())
	{
		std::cout << "File opening error!" << std::endl;
		return 1;
	}
	while (!file.eof() && file >> std::noskipws >> c)
		str += c;
	file.close();
	return (change(str, av));
}