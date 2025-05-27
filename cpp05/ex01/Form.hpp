#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Bureaucrat;

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

		Form(const std::string& name, const int r2s, const int r2e);
		Form(const int r2s, const int r2e);
		Form(const std::string& name);

		void beSigned(const Bureaucrat& ref);
		int r2s();
		int r2e();

		const std::string getName();
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
