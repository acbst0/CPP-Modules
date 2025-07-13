#include "Span.hpp"

Span::Span() : _capacity(0) {}

Span::Span(const Span& ref) : _capacity(ref._capacity), _nums(ref._nums) {}

Span::~Span() {}

Span::Span(unsigned int i) : _capacity(i) {}

Span& Span::operator=(const Span& ref)
{
	this->_capacity = ref._capacity;
	this->_nums = ref._nums;
	return *this;
}

void Span::addNumber(int num)
{
	if (this->_nums.size() + 1 > this->_capacity)
		throw CapacityOverflow();
	else
	{
		this->_nums.push_back(num);
	}
}

int Span::shortestSpan() const
{
	if (_nums.size() < 2)
		throw std::logic_error("Not enough elements");

	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_nums.size() < 2)
		throw std::logic_error("Not enough elements");

	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());

	int maxSpan = sorted[sorted.size() - 1] - sorted[0];
	return maxSpan;
}

const char* Span::CapacityOverflow::what() const throw()
{
	return ("Not Enough Capacity! Capacity Overflow");
}