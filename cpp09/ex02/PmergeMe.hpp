#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>
# include <sstream>
# include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;
		
		// Ford-Johnson algorithm for vector
		void fordJohnsonVector(std::vector<int>& arr);
		void insertSortVector(std::vector<int>& arr, int n);
		
		// Ford-Johnson algorithm for deque
		void fordJohnsonDeque(std::deque<int>& arr);
		void insertSortDeque(std::deque<int>& arr, int n);
		
		// Jacobsthal numbers generation
		std::vector<int> generateJacobsthalSequence(int n);
		
		// Binary search insertion
		void binaryInsertVector(std::vector<int>& arr, int val, int start, int end);
		void binaryInsertDeque(std::deque<int>& arr, int val, int start, int end);
		
		// Utility functions
		bool isValidNumber(const std::string& str);
		void parseInput(int ac, char **av);
		void printSequence(const std::vector<int>& seq, const std::string& label);
		double getTimeInMicroseconds(const struct timeval& start, const struct timeval& end);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& ref);
		
		void processInput(int ac, char **av);
		
		class InvalidInputError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
