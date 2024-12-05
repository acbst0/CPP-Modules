#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# define MAX_CONT 8

class PhoneBook
{
	private:
		int	_input_times;
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