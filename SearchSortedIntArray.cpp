#include <iostream>
#include <vector>
#include <algorithm>

// takes a sorted vector of integers and binary searches
// for the index of a given key
// returns -1 if the index isn't found
int searchIntArray(int key, std::vector<int> & arrayToSearch) {

	// set initial indices
	int startIndex = 0;
	int endIndex = arrayToSearch.size() - 1;
	int index = (startIndex + endIndex) / 2;

	while (startIndex <= endIndex) {
		if (key < arrayToSearch[index]) {
			// iterate on the lower range
			endIndex = index - 1;
			if (startIndex <= endIndex) {
				index = (startIndex + endIndex) / 2;
			}
			else {
				break;
			}
		}
		else if (key > arrayToSearch[index]) {
			// iterate on the higher range
			startIndex = index + 1;
			if (startIndex <= endIndex) {
				index = (startIndex + endIndex) / 2;
			}
			else {
				break;
			}
		}
		else {
			// index of key found, return it
			return index;
		}
	}

	return -1;

}

int main() {

	int someInts[] = { 1,2,34,5,4,3,234,235,293,65 };
	std::vector<int> muhInts(someInts,someInts+10);

	for (auto a : muhInts) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	std::sort(muhInts.begin(), muhInts.end());

	for (auto a : muhInts) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	std::cout << "Index of 1: " << searchIntArray(1, muhInts) << std::endl;
	std::cout << "Index of 2: " << searchIntArray(2, muhInts) << std::endl;
	std::cout << "Index of 20: " << searchIntArray(20, muhInts) << std::endl;
	std::cout << "Index of 35: " << searchIntArray(35, muhInts) << std::endl;
	std::cout << "Index of 234: " << searchIntArray(234, muhInts) << std::endl;
	std::cout << "Index of 293: " << searchIntArray(293, muhInts) << std::endl;

	std::cin.get();

	return 0;
}