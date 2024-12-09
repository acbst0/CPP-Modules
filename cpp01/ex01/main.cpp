/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:51:49 by abostano          #+#    #+#             */
/*   Updated: 2024/12/09 14:51:50 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 5;

    Zombie* head;
    head = zombieHorde(i, "Dzeko");
    for (int j = 0; j < i; j++)
        head[j].announce();
    
    delete[] head;
}