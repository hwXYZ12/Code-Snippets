// solves this problem (found here: http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf)
/*Write a program to determine whether an input string x is a substring of another
input string y.  (For example, "bat" is a substring of "abate", but not of "beat".)  You
may use any language you like*/

#include <string>
#include <iostream>

// b has substring a
bool hasSubstring(const std::string & a, const std::string & b) {

	// sanity checks
	if (a.empty()) {
		return true;
	}

	if (b.empty()) {
		return false;
	}

	int x = 0;
	int y = 0;
	for (x; x < b.size(); ++x) {
		if (b[x] == a[y]) {
			// increment y forward
			++y;
			if (y >= a.size()) {
				return true;
			}
		}
		else {
			y == 0;
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

	std::cin.get();

	return 0;
}