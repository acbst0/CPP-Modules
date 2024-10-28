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

//1:43 - 2:10
//