#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <sstream>

class RPN
{
	private:
		std::stack<int> _stack;
		std::string input;

		void processToken(const std::string& token);
		bool isOperator(const std::string& token);
		bool isNumber(const std::string& token);
		int performOperation(int a, int b, char op);

	public:
		RPN();
		RPN(const RPN& ref);
		~RPN();
		RPN& operator=(const RPN& ref);

		RPN(std::string str);
		void calculate();

		class InvalidExpressionError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif