// solution to this problem (found here http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf):
/*Write a function to remove a single occurrence of an integer from a doubly linked 
list if it is present.  You may use any language you like.*/

#include <iostream>

template <class T>
class Node {

private:
	Node * forward;
	Node * backward;
	T val;

public:
	Node(Node * forward, Node * backward, T value):forward(forward),backward(backward),val(value){}

	// linear search for the value
	Node * findVal(typename T value) {

		Node * head = this;

		while (head) {
			if (head->val == value){
				return head;
			}
			head = head->forward;
		}
		return nullptr;
	}

	void deleteNode() {

		// have forward node point to backward node
		if (this->forward != nullptr) {
			this->forward->backward = this->backward;
		}

		// have backward node point to the forward node
		if (this->backward != nullptr) {
			this->backward->forward = this->forward;
		}

		// can destruct this node
		forward = nullptr;
		backward = nullptr;
		
		~Node();

	}

	// basic mutator
	void setForward(Node * other) {
		forward = other;
	}

	// basic print
	void print() {

		Node * head = this;

		while (head) {
			std::cout << head->val << std::endl;
			head = head->forward;
		}

	}

	~Node() {
		// use some fancy C++ to determine how to destruct the value
		// contained in the linked list
		//delete val;
	}

};

int main() {

	Node<int> a = Node<int>(nullptr, nullptr,-10);
	Node<int> b = Node<int>(nullptr, &a, 5);
	Node<int> c = Node<int>(nullptr, &b, 9);
	Node<int> d = Node<int>(nullptr, &c, -3);
	Node<int> e = Node<int>(nullptr, &d, 7);

	a.setForward(&b);
	b.setForward(&c);
	c.setForward(&d);
	d.setForward(&e);

	a.print();
	Node<int> * whichNode = a.findVal(-4);
	if (whichNode != nullptr) {
		std::cout << "Node found, deleting" << std::endl;
	}
	else {
		std::cout << "Node not found, moving on" << std::endl;
	}
	a.print();
	whichNode = a.findVal(9);
	if (whichNode != nullptr) {
		std::cout << "Node found, deleting" << std::endl;
		whichNode->deleteNode();
	}
	else {
		std::cout << "Node not found, moving on" << std::endl;
	}
	a.print();

	std::cin.get();

	return 0;
}