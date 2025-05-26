#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureucrat();
		Bureucrat(const Bureucrat& ref);
		~Bureucrat();
		Bureucrat& operator=(const Bureucrat& ref);
		
		Bureucrat(const std::string name);
		Bureucrat(int grade);
		Bureucrat(const std::string name, int grade);

		const std::string getName();
		int getGrade() const;
		void setGrade(int grade);

		void increment();
		void decrement();

		void signForm(Form& ref);

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

std::ostream& operator<<(std::ostream& out, Bureucrat& ref);

#endif