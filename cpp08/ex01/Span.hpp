#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int _capacity;
		std::vector<int> _nums;
	public:
		Span();
		Span(const Span& ref);
		~Span();

		Span(unsigned int i);

		Span& operator=(const Span& ref);

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;



		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			std::size_t count = std::distance(begin, end);
			if (this->_nums.size() + count > this->_capacity)
				throw CapacityOverflow();
			for (Iterator it = begin; it != end; ++it)
				this->addNumber(*it);
		}

		class CapacityOverflow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif