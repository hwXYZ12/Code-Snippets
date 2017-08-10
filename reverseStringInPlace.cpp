#include <iostream>
#include <string>

void reverseString(std::string::iterator & start, std::string::iterator & end) {

	if (start <= end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		reverseString(start + 1, end - 1);
	}
}

int main() {

	std::string someString = "ayy lmao";

	std::cout << someString << std::endl;

	reverseString(someString.begin(), someString.end() - 1);

	std::cout << someString << std::endl;

	std::cin.get();

	return 0;
}