#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>

class Bureucrat
{
	private:
		const std::string _name;
		size_t _grade;
	public:
		Bureucrat();
		Bureucrat(const Bureucrat& ref);
		Bureucrat(const std::string name);
		Bureucrat(size_t grade);
		Bureucrat(const std::string name, size_t grade);
		~Bureucrat();
		Bureucrat& operator=(const Bureucrat& ref);

		const std::string getName();

		size_t getGrade();
		void setGrade(size_t grade);

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

std::ostream& operator<<(std::ostream& out, Bureucrat& ref);

#endif