#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime> 

class RobotomyRequestForm : public AForm
{
	private:
		// Sign 72
		// Exec 45
		std::string _target;
		virtual void action() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

		RobotomyRequestForm(const std::string& target);
		const std::string& getTarget() const;

		class RobotomizedFailed : public std::exception
		{
			private:
				virtual const char* what() const throw();
		};
};

#endif