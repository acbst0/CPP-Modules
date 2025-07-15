#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		// sign 145
		// exec 137
		std::string _target;
		virtual void action() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

		ShrubberyCreationForm(const std::string& target);

		class OpenFileExeption : public std::exception
		{
			private:
				virtual const char* what() const throw();
		};
		const std::string& getTarget() const;
};

#endif