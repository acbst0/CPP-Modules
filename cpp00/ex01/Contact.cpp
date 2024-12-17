/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:43 by abostano          #+#    #+#             */
/*   Updated: 2024/12/17 12:27:44 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_Empty = false;
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkness)
{
	this->_FirstName = firstname;
	this->_LastName = lastname;
	this->_NickName = nickname;
	this->_PhoneNum = phonenum;
	this->_Darkness = darkness;
	this->_Empty = true;
}

Contact::~Contact()
{

}

std::string	Contact::getFirstName()
{
	return (this->_FirstName);
}

std::string	Contact::getLastName()
{
	return (this->_LastName);
}

std::string	Contact::getNickName()
{
	return (this->_NickName);
}

std::string	Contact::getPhoneNum()
{
	return (this->_PhoneNum);
}

std::string	Contact::getDarkness()
{
	return (this->_Darkness);
}

void	Contact::makeEmpty()
{
	this->_Empty = false;
}

bool	Contact::getEmpty()
{
	return (this->_Empty);
}