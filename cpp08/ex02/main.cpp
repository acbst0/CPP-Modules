#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "Mutant Stack has been created!" << std::endl;
	std::cout << "Size => " << mstack.size() << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Size after two element => " << mstack.size() << std::endl;
	std::cout << "Top element of Mutant Stack => "<< mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after one last element poped => " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "All elements :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Size of original object of Mutant Stack => " << mstack.size() << std::endl;

	std::stack<int> s(mstack);
	std::cout << "Size of copy object of Mutant Stack => " << s.size() << std::endl;

	return 0;
}
