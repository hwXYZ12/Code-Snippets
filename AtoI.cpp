#include <iostream>
#include <string>

template<class intWidth>
intWidth AtoI(const std::string::iterator & start, const std::string::iterator & end) {

	// move past any initial whitespace
	std::string::iterator x = start;
	while (isspace(*x)){
		++x;
	}

	bool isNegative = false;

	// next character is a '+'
	if ((int)*x == '+') {
		++x;
	}
	else if ((int)*x == '-') {
		// next character is a '-'
		isNegative = true;
		++x;
	}


	intWidth ret = 0;
	// read as many digits as possible
	while ((int)*x >= '0' && (int)*x <= '9') {
		// add digit to total
		ret = ret*10 + (int)*x - '0';
		++x;
	}

	if (isNegative) {
		ret *= -1;
	}

	return ret;

}

int main() {

	std::string someString1 = "Ayo whatup";
	std::string someString2 = "123sld;kfjlsdkfj";
	std::string someString3 = "							12somethingspecial";
	std::string someString4 = "		-12some";
	std::string someString5 = "				+543ayylmao";

	std::cout << AtoI<int>(someString1.begin(), someString1.end()) << std::endl;
	std::cout << AtoI<long long>(someString2.begin(), someString2.end()) << std::endl;
	std::cout << AtoI<unsigned int>(someString3.begin(), someString3.end()) << std::endl;
	std::cout << AtoI<long>(someString4.begin(), someString4.end()) << std::endl;
	std::cout << AtoI<short>(someString5.begin(), someString5.end()) << std::endl;

	std::cin.get();

	return 0;
}