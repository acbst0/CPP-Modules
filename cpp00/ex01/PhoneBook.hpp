/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:28:03 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 12:28:04 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# define MAX_CONT 8

class PhoneBook
{
	private:
		int	_input_times;
		bool isNumber(std::string str);
	public:
		Contact cnt[MAX_CONT];
		PhoneBook();
		~PhoneBook();
		int	add(PhoneBook *pb);
		void	search(PhoneBook *pb);
		void	printPB();
		void	printCT(Contact *ct, int i);
};

#endif