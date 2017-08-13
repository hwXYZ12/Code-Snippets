// solution to this problem (found here http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf):
/*Describe a stack data structure that supports "push", "pop", and "find minimum" 
operations.  "Find minimum" returns the smallest element in the stack.*/

#include <stack>
#include <iostream>

class minStack {

private:
	std::stack<int> regStack;
	std::stack<int> mins;

public:

	minStack() : regStack(std::stack<int>()), mins(std::stack<int>()){}

	void pop() {

		// do nothing if either are empty
		if (regStack.empty() || mins.empty())
			return;

		// check if the value to be popped is the current minimum
		if (regStack.top() == mins.top()) {
			mins.pop();
		}
		regStack.pop();
	}

	void push(int val) {

		int currentMin = findMinimum();
		if (val <= currentMin) {
			mins.push(val);
		}
		regStack.push(val);
	}

	const int & findMinimum() {
		if (mins.empty()) {
			return INT_MAX;
		}
		return mins.top();
	}

};


int main() {

	using std::cout;
	using std::endl;

	minStack s = minStack();

	s.push(-1);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.push(-5);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.push(5);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.push(7);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.push(-6);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.push(10);
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;
	s.pop();
	cout << "Minimum: " << s.findMinimum() << endl;

	std::cin.get();

	return 0;
}