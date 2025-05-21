#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form
{
	private:
		const std::string _name;
		bool isSigned;
		const int required2sign;
		const int required2exec;

	public:
		Form();
		Form(const Form& ref);
		~Form();
		Form& operator=(const Form& ref);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
				
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, Form& ref);


#endif