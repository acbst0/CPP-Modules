/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:28:03 by abostano          #+#    #+#             */
/*   Updated: 2024/12/18 18:35:40 by abostano         ###   ########.fr       */
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
		int			_input_times;
		Contact		cnt[MAX_CONT];
		bool 		isNumber(std::string str);
		void		printPB();
		void		printCT(Contact *ct, int i);
		void		printline(std::string str);
		std::string	to_string(int value);
	public:
		PhoneBook();
		~PhoneBook();
		int			add(PhoneBook *pb);
		int			search(PhoneBook *pb);
};

#endif