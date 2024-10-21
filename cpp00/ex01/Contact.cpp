#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkness)
{
	this->_FirstName = firstname;
	this->_LastName = lastname;
	this->_NickName = nickname;
	this->_PhoneNum = phonenum;
	this->_Darkness = darkness;
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
