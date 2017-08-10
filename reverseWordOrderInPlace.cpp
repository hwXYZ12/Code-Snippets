#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

void reverseString(std::string::iterator start, std::string::iterator end){
	while(start <= end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverseOrderOfWords(std::string::iterator start, std::string::iterator end) {

	// reverse the whole string
	reverseString(start, end);

	// reverse each word one by one
	while (start <= end) {

		// scroll past initial whitespace
		while (isspace(*start)) {
			start++;
		}

		auto x = start;

		// scroll into the next patch of whitespace
		// or the end of the range
		while (start <= end && !isspace(*start)) {
			start++;
		}

		reverseString(x, start - 1);
	}

}

/* Couldn't progress with inplace reversal since the regex token iterator returns const iterators
void reverseOrderOfWords2(std::string::iterator start, std::string::iterator end) {

	// reverse string
	std::reverse(start, end);

	// tokenize each word using a regex
	std::regex nonWhiteSpaceRE("\\S+");
	
	// then reverse each of the words
	std::for_each(std::sregex_token_iterator(start, end, nonWhiteSpaceRE), std::sregex_token_iterator(),
		[](auto & s) {

		//std::cout << std::endl;

		//std::for_each(s.first, s.second, [](auto & t) { std::cout << t;});

		// reverse each string individually
		//std::reverse(*(s.first), *(s.second));
		//reverseString(s.first, s.second-1);

		// const iterators 
	});
}*/

int main() {

	std::string words = "Will is LUL xd";
	std::string wordsWithFriends = "xddddd don't     take     tooo  loooooong!!!";
	std::string lelkekXD = "hello world, my name is program :)";

	
	std::cout << std::endl;


	std::cout << words << std::endl;
	reverseOrderOfWords(words.begin(), words.end() - 1);
	std::cout << words << std::endl;

	std::cout << wordsWithFriends << std::endl;
	reverseOrderOfWords(wordsWithFriends.begin(), wordsWithFriends.end() - 1);
	std::cout << wordsWithFriends << std::endl;

	std::cout << lelkekXD << std::endl;
	reverseOrderOfWords(lelkekXD.begin(), lelkekXD.end() - 1);
	std::cout << lelkekXD << std::endl;

	std::cin.get();

	return 0;
}