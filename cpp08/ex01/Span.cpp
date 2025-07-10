#include "Span.hpp"

Span::Span() : _capacity(0), instant_size(0) {}

Span::Span(const Span& ref) : _capacity(ref._capacity), instant_size(ref.instant_size), _nums(ref._nums) {}

Span::~Span() {}

Span::Span(unsigned int i) : _capacity(i), instant_size(0) {}

Span& Span::operator=(const Span& ref)
{
	this->_capacity = ref._capacity;
	this->_nums = ref._nums;
	return *this;
}

void Span::addNumber(int num)
{
	if (this->instant_size + 1 > this->_capacity)
		throw CapacityOverflow();
	else
	{
		this->_nums.push_back(num);
		this->instant_size += 1;
	}
}

int Span::shortestSpan() const
{
	std::vector<int>::iterator i = 
}