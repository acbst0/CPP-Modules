#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:
		unsigned int _capacity;
		unsigned int instant_size;
		std::vector<int> _nums;
	public:
		Span();
		Span(const Span& ref);
		~Span();

		Span(unsigned int i);

		Span& operator=(const Span& ref);

		void addNumber(int num);
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);
		int shortestSpan() const;
		int longestSpan() const;

		class CapacityOverflow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Span.tpp"

#endif