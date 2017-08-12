// solves this problem (found here http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Handout_3.pdf):
/*Let's say you've just kidnapped Alyssa Hacker you want to leave a ransom note for 
Ben Bitdiddle, saying that if he ever wants to see her again, he needs to swear to 
never use Scheme again.  You don't want to write the note by hand, since they would 
be able to trace your handwriting.  You're standing in Alyssa's apartment and you 
see a million computer magazines.  You need to write your note by cutting letters 
out of the magazines and pasting them together to form a letter.  Here's the 
question: given an arbitrary ransom note string and another string containing all the 
contents of all the magazines, write a function that will return true if the ransom 
note can be made from the magazines; otherwise, it will return false.  Remember, 
every letter found in the magazine string can only be used once in your ransom note*/

#include <string>
#include <unordered_map>
#include <iostream>

bool canStringBeBuilt(const std::string & target,const std::string & source) {

	// count letters in target using a hashmap
	auto letterCount = std::unordered_map<char, int>();

	// loop through entire target string and place the letter
	// count into the hash map
	for (int i = 0; i < target.size(); ++i) {
		if (letterCount.count(target[i]) == 0) {
			letterCount[target[i]] = 1;
		}
		else {
			++letterCount[target[i]];
		}
	}

	// loop through entire source string and decrement the letter
	// count if it is a letter we need until 0
	for (int i = 0; i < source.size(); ++i) {
		if (letterCount.count(source[i]) != 0 && letterCount[source[i]] > 0) {
			--letterCount[source[i]];
		}
	}

	// if all of the letterCount values
	// end up zero, we know we have enough letters
	// to build the target string
	for (auto it : letterCount) {
		if (it.second != 0) {
			return false;
		}
	}
	return true;


}

int main() {

	using std::cout;
	using std::endl;


	// test
	cout << canStringBeBuilt("abc", "abcdefghijk") << endl;
	cout << canStringBeBuilt("nope", "absolutely not") << endl;
	cout << canStringBeBuilt("yes", "always and forever I want to be with you and make believe with you");

	std::cin.get();

	return 0;
}