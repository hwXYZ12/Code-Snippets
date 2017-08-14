// solution to this problem (found here http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_B.pdf):
/*You're given an unsorted array of integers where every integer appears exactly 
twice, except for one integer which appears only once.  Write an algorithm (in a 
language of your choice) that finds the integer that appears only once*/

#include <unordered_map>
#include <vector>

int findOddManOut(std::vector<int> & nums) {

	// walk through the list of numbers and
	// place each number in a hash map
	auto map = std::unordered_map<int, int>();
	int ret = -1;
	for (auto x : nums) {
		if (map.count(x) == 0) {
			map[x] = 1;
		}
		else {
			++map[x];
		}
	}

	for (auto x : nums) {
		if (map[x] == 1) {
			return x;
		}
	}

}

int main() {
	return 0;
}