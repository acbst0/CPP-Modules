#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& ref);
		
		Bureaucrat(const std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);

		const std::string getName();
		int getGrade() const;
		void setGrade(int grade);

		void increment();
		void decrement();

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

std::ostream& operator<<(std::ostream& out, Bureaucrat& ref);

#endif
