#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& ref)
{
	this->_stack = ref._stack;
	this->input = ref.input;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& ref)
{
	if (this != &ref)
	{
		this->_stack = ref._stack;
		this->input = ref.input;
	}
	return *this;
}

RPN::RPN(std::string str) : input(str)
{
	calculate();
}

bool RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token)
{
	if (token.empty())
		return false;
	
	size_t start = 0;
	if (token[0] == '-' || token[0] == '+')
		start = 1;
	
	if (start >= token.length())
		return false;
	
	for (size_t i = start; i < token.length(); i++)
	{
		if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}

int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw DivisionByZeroError();
			return a / b;
		default:
			throw InvalidExpressionError();
	}
}

void RPN::processToken(const std::string& token)
{
	if (isNumber(token))
	{
		int num = std::atoi(token.c_str());
		if (num >= 10 || num < 0)
			throw InvalidExpressionError();
		_stack.push(num);
	}
	else if (isOperator(token))
	{
		if (_stack.size() < 2)
			throw InvalidExpressionError();
		
		int b = _stack.top();
		_stack.pop();
		int a = _stack.top();
		_stack.pop();
		
		int result = performOperation(a, b, token[0]);
		_stack.push(result);
	}
	else
	{
		throw InvalidExpressionError();
	}
}

void RPN::calculate()
{
	std::istringstream iss(input);
	std::string token;
	
	while (iss >> token)
	{
		processToken(token);
	}
	
	if (_stack.size() != 1)
		throw InvalidExpressionError();
	
	std::cout << _stack.top() << std::endl;
}

const char* RPN::InvalidExpressionError::what() const throw()
{
	return "Error! Invalid expression.";
}

const char* RPN::DivisionByZeroError::what() const throw()
{
	return "Error! Division by zero.";
}