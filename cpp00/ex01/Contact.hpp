/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:53 by abostano          #+#    #+#             */
/*   Updated: 2024/12/18 14:17:01 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

# define LIGHT_BLUE "\001\033[1;94m\002"
# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define GRAY "\001\033[1;90m\002"

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNum;
		std::string	_Darkness;
		bool		_Empty;
	public:
		Contact();
		~Contact();
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkness);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNum();
		std::string	getDarkness();
		void		makeEmpty();
		bool		getEmpty();

};

#endif
