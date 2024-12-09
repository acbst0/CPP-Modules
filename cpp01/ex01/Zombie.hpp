/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:23:09 by abostano          #+#    #+#             */
/*   Updated: 2024/12/09 12:46:37 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void    setname(std::string name);
        void    announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif