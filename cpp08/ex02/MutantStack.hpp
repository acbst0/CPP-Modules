#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		std::vector<T> _elements;
	public:
		MutantStack();
		MutantStack(const MutantStack& ref);
		~MutantStack();
		MutantStack& operator=(const MutantStack& ref);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif