
class Node {
	public:
		int value;
		Node *nextPtr;
		Node *prevPtr;

		Node(int v) {
			value = v;
			nextPtr = 0;
			prevPtr = 0;
		}
		
};
