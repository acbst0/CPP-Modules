#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form frm1("Politic", 12, 12);
	Form frm2("Economic", 9, 9);
	Bureaucrat one("Jack", 11);

	std::cout << frm1;
	std::cout << frm2;

	one.signForm(frm1);
	one.signForm(frm2);
	return 0;
}
