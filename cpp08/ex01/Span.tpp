template <typename Iterator>
void addNumbers(Iterator begin, Iterator end)
{
	for (Iterator i = begin; i != end; i++)
	{
		this->addNumber(*i);
	}
}