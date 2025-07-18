#include "Array.hpp"
#include <string>

int main() {
	std::cout << "===== INT ARRAY TEST =====" << std::endl;
	Array<int> intArr(5);
	for (size_t i = 0; i < intArr.size(); ++i)
		intArr[i] = static_cast<int>(i * 10);

	for (size_t i = 0; i < intArr.size(); ++i)
		std::cout << "intArr[" << i << "] = " << intArr[i] << std::endl;

	try {
		std::cout << "Trying out-of-bounds access..." << std::endl;
		std::cout << intArr[10] << std::endl; // should throw
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n===== STRING ARRAY TEST =====" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Ahmet";
	strArr[1] = "Cemil";
	strArr[2] = "Bostanoğlu";

	for (size_t i = 0; i < strArr.size(); ++i)
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

	std::cout << "\n===== COPY CONSTRUCTOR TEST =====" << std::endl;
	Array<std::string> copyArr(strArr);
	for (size_t i = 0; i < copyArr.size(); ++i)
		std::cout << "copyArr[" << i << "] = " << copyArr[i] << std::endl;

	std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
	Array<std::string> assignedArr;
	assignedArr = strArr;
	for (size_t i = 0; i < assignedArr.size(); ++i)
		std::cout << "assignedArr[" << i << "] = " << assignedArr[i] << std::endl;

	return 0;
}
