// checks if a binary search tree fulfills the search tree condition
// tree class left out for brevity

bool isBST(Node * head) {
	return isBST_Helper(head, INT_MAX, INT_MIN);
}

bool isBST_Helper(Node * head, int max, int min) {

	return isBST_Helper(head->leftChild, head->val, min)
		&& (head->val < max)
		&& isBST_Helper(head->rightChild, max, head->val)
		&& (head->val > min)
		&& (head->leftChild && head->leftChild->val < head->val)
		&& (head->rightChild && head->rightChild->val >= head->val);

}