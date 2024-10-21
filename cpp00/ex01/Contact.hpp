#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNum;
		std::string	_Darkness;
	public:
		Contact();
		~Contact();
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string darkness);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNum();
		std::string	getDarkness();

};

#endif