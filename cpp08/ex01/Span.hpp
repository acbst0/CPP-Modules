#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	private:
		unsigned long _capacity;
	public:
		Span();
		Span(Span& ref);
		~Span();
		Span& operator=(Span& ref);

		Span(unsigned long int i);
		void addNumber(int i);
};

#endif