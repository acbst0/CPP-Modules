#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define MAX_CONT 8

class PhoneBook
{
	private:
		int	_input_times;
	public:
		Contact cnt[MAX_CONT];
		PhoneBook();
		~PhoneBook();
		void	add(PhoneBook *pb);
		void	search(PhoneBook *pb);
};


#endif