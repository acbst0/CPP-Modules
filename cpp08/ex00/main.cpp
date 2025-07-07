#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::cout << "===== VECTOR TEST =====" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i * 10);

	try {
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 99);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== LIST TEST =====" << std::endl;
	std::list<int> lst;
	for (int i = 1; i <= 5; ++i)
		lst.push_back(i);

	try {
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== DEQUE TEST =====" << std::endl;
	std::deque<int> dq;
	dq.push_back(100);
	dq.push_back(200);
	dq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(dq, 200);
		std::cout << "Found in deque: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
