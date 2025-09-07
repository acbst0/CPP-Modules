#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& ref)
{
	this->_vectorData = ref._vectorData;
	this->_dequeData = ref._dequeData;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
{
	if (this != &ref)
	{
		this->_vectorData = ref._vectorData;
		this->_dequeData = ref._dequeData;
	}
	return *this;
}

bool PmergeMe::isValidNumber(const std::string& str)
{
	if (str.empty() || str[0] == '-')
		return false;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	long num = std::atol(str.c_str());
	return (num >= 0 && num <= 2147483647);
}

void PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		if (!isValidNumber(str))
			throw InvalidInputError();
		
		int num = std::atoi(str.c_str());
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	
	if (_vectorData.empty())
		throw InvalidInputError();
}

void PmergeMe::printSequence(const std::vector<int>& seq, const std::string& label)
{
	std::cout << label;
	if (seq.size() <= 5)
	{
		for (size_t i = 0; i < seq.size(); i++)
		{
			std::cout << seq[i];
			if (i < seq.size() - 1)
				std::cout << " ";
		}
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
		{
			std::cout << seq[i] << " ";
		}
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

double PmergeMe::getTimeInMicroseconds(const struct timeval& start, const struct timeval& end)
{
	return ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec));
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
	std::vector<int> jacobsthal;
	if (n <= 0) return jacobsthal;
	
	jacobsthal.push_back(1);
	if (n > 1) jacobsthal.push_back(1);
	
	for (int i = 2; jacobsthal[i-1] < n; i++)
	{
		int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
		if (next > n) break;
		jacobsthal.push_back(next);
	}
	
	return jacobsthal;
}

void PmergeMe::binaryInsertVector(std::vector<int>& arr, int val, int start, int end)
{
	if (start >= end)
	{
		arr.insert(arr.begin() + start, val);
		return;
	}
	
	int mid = start + (end - start) / 2;
	if (val <= arr[mid])
		binaryInsertVector(arr, val, start, mid);
	else
		binaryInsertVector(arr, val, mid + 1, end);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& arr, int val, int start, int end)
{
	if (start >= end)
	{
		arr.insert(arr.begin() + start, val);
		return;
	}
	
	int mid = start + (end - start) / 2;
	if (val <= arr[mid])
		binaryInsertDeque(arr, val, start, mid);
	else
		binaryInsertDeque(arr, val, mid + 1, end);
}

void PmergeMe::insertSortVector(std::vector<int>& arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::insertSortDeque(std::deque<int>& arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
	int n = arr.size();
	if (n <= 1)
		return;
	
	if (n <= 20)
	{
		insertSortVector(arr, n);
		return;
	}
	
	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = (n % 2 == 1);
	int oddElement;
	if (hasOdd)
		oddElement = arr[n-1];
	else
		oddElement = 0;
	
	for (int i = 0; i < n - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
	}
	
	std::vector<int> larger, smaller;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		larger.push_back(pairs[i].first);
		smaller.push_back(pairs[i].second);
	}
	fordJohnsonVector(larger);
	arr = larger;
	if (!smaller.empty())
		arr.insert(arr.begin(), smaller[0]);

	std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());
	std::vector<bool> inserted(smaller.size(), false);
	if (!smaller.empty()) inserted[0] = true;
	
	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		int start;
		if (i > 1)
			start = jacobsthal[i-1];
		else
			start = 1;
		int end = std::min(jacobsthal[i], static_cast<int>(smaller.size()));
		
		for (int j = end - 1; j >= start && j < static_cast<int>(smaller.size()); j--)
		{
			if (!inserted[j])
			{
				binaryInsertVector(arr, smaller[j], 0, arr.size());
				inserted[j] = true;
			}
		}
	}

	for (size_t i = 1; i < smaller.size(); i++)
	{
		if (!inserted[i])
			binaryInsertVector(arr, smaller[i], 0, arr.size());
	}
	if (hasOdd)
		binaryInsertVector(arr, oddElement, 0, arr.size());
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
	int n = arr.size();
	if (n <= 1)
		return;
	if (n <= 20)
	{
		insertSortDeque(arr, n);
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	bool hasOdd = (n % 2 == 1);
	int oddElement;
	if (hasOdd)
		oddElement = arr[n-1];
	else
		oddElement = 0;
	
	for (int i = 0; i < n - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
	}
	
	std::deque<int> larger, smaller;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		larger.push_back(pairs[i].first);
		smaller.push_back(pairs[i].second);
	}
	
	fordJohnsonDeque(larger);
	arr = larger;
	if (!smaller.empty())
		arr.insert(arr.begin(), smaller[0]);
	std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());
	std::vector<bool> inserted(smaller.size(), false);
	if (!smaller.empty()) inserted[0] = true;
	
	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		int start;
		if (i > 1)
			start = jacobsthal[i-1];
		else
			start = 1;
		int end = std::min(jacobsthal[i], static_cast<int>(smaller.size()));
		
		for (int j = end - 1; j >= start && j < static_cast<int>(smaller.size()); j--)
		{
			if (!inserted[j])
			{
				binaryInsertDeque(arr, smaller[j], 0, arr.size());
				inserted[j] = true;
			}
		}
	}
	
	for (size_t i = 1; i < smaller.size(); i++)
	{
		if (!inserted[i])
			binaryInsertDeque(arr, smaller[i], 0, arr.size());
	}
	if (hasOdd)
		binaryInsertDeque(arr, oddElement, 0, arr.size());
}

void PmergeMe::processInput(int ac, char **av)
{
	parseInput(ac, av);
	printSequence(_vectorData, "Before: ");
	std::vector<int> vectorCopy = _vectorData;
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	fordJohnsonVector(vectorCopy);
	gettimeofday(&end, NULL);
	double vectorTime = getTimeInMicroseconds(start, end);
	std::deque<int> dequeCopy = _dequeData;
	
	gettimeofday(&start, NULL);
	fordJohnsonDeque(dequeCopy);
	gettimeofday(&end, NULL);
	double dequeTime = getTimeInMicroseconds(start, end);

	std::vector<int> sortedVector(vectorCopy.begin(), vectorCopy.end());
	printSequence(sortedVector, "After:  ");
	
	std::cout << "Time to process a range of " << _vectorData.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}

const char* PmergeMe::InvalidInputError::what() const throw()
{
	return "Error";
}
