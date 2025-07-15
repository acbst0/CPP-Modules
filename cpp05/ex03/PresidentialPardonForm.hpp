#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	// sign 25
	// exec 5
	private:
		std::string _target;
		virtual void action() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

		PresidentialPardonForm(const std::string& target);
		const std::string& getTarget() const;
};

#endif