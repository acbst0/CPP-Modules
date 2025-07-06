#include "iter.hpp"

void printElement(const int& ref)
{
	std::cout << ref << std::endl;
}

template <typename T>
void printOther(const T& ref)
{
	std::cout << ref << std::endl;
}

void increment(int &ref)
{
	ref += 1;
}

int main(void)
{
	int arr[4] = {1,2,3,4};

	std::cout << "---------------------" << std::endl;
	std::cout << "   Before Increment" << std::endl;
	std::cout << "---------------------" << std::endl;


	iter<int>(arr, 4, printElement);


	std::cout << "---------------------" << std::endl;
	std::cout << "   After Increment" << std::endl;
	std::cout << "---------------------" << std::endl;


	iter<int>(arr, 4, increment);
	iter<int>(arr, 4, printElement);
/* 
	// String Test
	std::string strings[] = {"Ahmet", "Cemil", "Bostanoglu"};
	iter<std::string>(strings, 3, printOther<std::string>);

	// Float Test
	float floats[] = {1.1f, 2.2f, 3.3f};
	iter<float>(floats, 3, printOther<float>);
*/
}