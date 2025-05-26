#include "Bureucrat.hpp"
#include "AForm.hpp"

int main()
{
	AForm frm1("Politic", 12, 12);
	AForm frm2("Economic", 9, 9);
	Bureucrat one("Jack", 11);

	std::cout << frm1;
	std::cout << frm2;

	one.signForm(frm1);
	one.signForm(frm2);
	return 0;
}