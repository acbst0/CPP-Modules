/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:52:50 by abostano          #+#    #+#             */
/*   Updated: 2024/12/16 15:24:59 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon		&_wpn;
	public:
		HumanA(std::string name, Weapon &wpn);
		~HumanA(void);
		void attack(void);
		void setWeapon(Weapon wpn);
};