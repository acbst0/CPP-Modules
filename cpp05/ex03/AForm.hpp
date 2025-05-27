#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool isSigned;
		const int required2sign;
		const int required2exec;
		virtual void action() const = 0;

	public:
		AForm();
		AForm(const AForm& ref);
		~AForm();
		AForm& operator=(const AForm& ref);

		AForm(const std::string& name, const int r2s, const int r2e);
		AForm(const int r2s, const int r2e);
		AForm(const std::string& name);

		void beSigned(const Bureaucrat& ref);
		int r2s();
		int r2e();

		const std::string getName();
		void setisSigned(const AForm& ref);

		void execute(const Bureaucrat& executor) const;
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
		class IsNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, AForm& ref);


#endif
