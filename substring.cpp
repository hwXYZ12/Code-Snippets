// solves this problem (found here: http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf)
/*Write a program to determine whether an input string x is a substring of another
input string y.  (For example, "bat" is a substring of "abate", but not of "beat".)  You
may use any language you like*/

#include <string>
#include <iostream>

// b has substring a, using bruteforce for O(|a|*|b|) complexity
// since O(|a|+|b|) complexity is nontrivial
bool hasSubstring(const std::string & a, const std::string & b) {

	// sanity checks
	if (a.empty()) {
		return true;
	}

	if (b.empty()) {
		return false;
	}

	for (int x=0; x < b.size(); ++x) {
		bool isAMatch = true;
		for (int j = 0; j < a.size(); ++j) {
			if (b[x + j] != a[j]) {
				isAMatch = false;
				break;
			}
		}
		if (isAMatch) {
			return true;
		}
	}
	return false;

}

int main() {

	using std::cout;
	using std::endl;

	cout << hasSubstring("abcd","not even close bby") << endl;
	cout << hasSubstring("how about now?", "sure, 'how about now?' is fine") << endl;
	cout << hasSubstring("xyz","xyabcdxygegfxyas;dlkfjxyz") << endl;
	cout << hasSubstring("fair enough", "denied") << endl;
	cout << hasSubstring("ananab", "anananab") << endl;

	std::cin.get();

	return 0;
}