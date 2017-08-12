// Finds a path between two nodes in a binary tree

#include <iostream>
#include <vector>
#include <unordered_map>

template<class T>
class BST {

public:

	class Node {

	public:

		Node * childLeft;
		Node * childRight;
		T val;

		Node(Node * childLeft, Node * childRight, T value) : childLeft(childLeft), childRight(childRight), val(value) {}

	};

	Node * head;

	BST(Node * head) : head(head) {}

	void getPathToNode(Node & whichNode,
						std::vector<Node *> & pathAsVector) {
		
		// clear return vector and add the head node
		pathAsVector.clear();

		T key = whichNode.val;

		Node * next = head;

		bool foundKey = false;

		while (next) {
			pathAsVector.push_back(next);
			if (key < next->val) {
				// less than the node value
				// iterate on left subtree
				next = next->childLeft;
			}
			else if (key > next->val) {
				// greater than the node value
				// iterate on right subtree
				next = next->childRight;
			} else {
				// found the key
				foundKey = true;
				break;
			}
		}

		// key wasn't found
		if (!foundKey) {
			pathAsVector.clear();
		}
	}

	void getPathToNodeWithMarkers(Node & whichNode,
		std::vector<Node *> & pathAsVector,
		std::unordered_map<Node *, int> & markers) {

		// clear return vector and add the head node
		pathAsVector.clear();

		T key = whichNode.val;

		Node * next = head;

		bool foundKey = false;

		while (next) {
			pathAsVector.push_back(next);
			if (markers.count(next) != 0) {
				++markers[next];
			}
			else {
				markers[next] = 1;
			}
			if (key < next->val) {
				// less than the node value
				// iterate on left subtree
				next = next->childLeft;
			}
			else if (key > next->val) {
				// greater than the node value
				// iterate on right subtree
				next = next->childRight;
			}
			else {
				// found the key
				foundKey = true;
				break;
			}
		}

		// key wasn't found
		if (!foundKey) {
			pathAsVector.clear();
		}
	}

	void findPathBetweenNodes(	Node & element1,
								Node & element2,
								std::vector<typename BST<T>::Node *> & pathAsVector) {

		// use an unordered_map to mark the visited nodes
		auto markers = std::unordered_map<Node *, int>();

		// get path to the first node
		auto firstPath = std::vector<Node *>();
		getPathToNodeWithMarkers(element1, firstPath, markers);

		// get path to the second node
		auto secondPath = std::vector<Node *>();
		getPathToNodeWithMarkers(element2, secondPath, markers);

		// fuse the paths

		// clear return vector
		pathAsVector.clear();

		// start from the back of the first path
		for (int i = firstPath.size() - 1; i >= 0; --i) {
			if (markers[firstPath[i]] == 1) {
				pathAsVector.push_back(firstPath[i]);
			}
		}

		// skip the nodes that were marked twice (except the last one)
		int i = 0;
		while (markers[secondPath[i]] == 2) {
			++i;
		}
		--i;

		// push the nodes from the second path
		// starting from the shared head node
		for (i; i < secondPath.size(); ++i) {
			pathAsVector.push_back(secondPath[i]);
		}
	}


};

int main() {

	using std::cout;
	using std::endl;

	// build some tree nodes
	auto n1 = BST<int>::Node(nullptr, nullptr, 7);
	auto n2 = BST<int>::Node(nullptr, nullptr, 10);
	auto n3 = BST<int>::Node(nullptr, nullptr, -20);
	auto n4 = BST<int>::Node(nullptr, nullptr, -3);

	auto n5 = BST<int>::Node(&n3, &n4, -5);
	auto n6 = BST<int>::Node(&n1, &n2, 8);

	auto n7 = BST<int>::Node(&n5, &n6, 2);

	// build the tree
	auto theTree = BST<int>(&n7);

	// get the path from -20 to -3 and print
	auto path = std::vector<BST<int>::Node *>();
	theTree.findPathBetweenNodes(n3, n4, path);

	cout << "First path" << endl;
	for (auto x : path) {
		cout << x->val << endl;
	}

	// get the path from -3 to 8 and print
	path.clear();
	theTree.findPathBetweenNodes(n4, n1, path);

	cout << "Second path" << endl;
	for (auto x : path) {
		cout << x->val << endl;
	}

	std::cin.get();

	return 0;
}