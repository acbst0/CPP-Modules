/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:56:19 by abostano          #+#    #+#             */
/*   Updated: 2024/12/07 13:09:52 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* newzomb = newZombie("NewZombie");
    newzomb->announce();
    randomChump("RndZombie");
    delete newzomb;
}