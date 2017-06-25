#include <string>
#include <deque>

using namespace std;
struct Node
{
	Node *up, *left, *right;
	int data;
};

class BinarySearchTree
{

public:
	int size = 0;
	Node * root;
	std::string cr, cl, cp;
	Node * getRoot();
	BinarySearchTree();
	~BinarySearchTree();
	void removeTree(Node * root);
	int getSize();
	void createRandomTree(int numberOfValues);
	Node * searchForValue(Node* node,int value);
	void printBT(string sp, string sn,Node * root);
	Node * predecessor(Node * p);
	Node * successor(Node * p);
	Node * minNode(Node*root);
	Node * maxNode(Node*root);
	Node * deleteNode(Node * root);
	void rebalanceDSW();
	Node * doTurnRight(int value);
	Node * doTurnLeft(int value);
	void rotateLeft(Node * A);
	void rotateRight(Node * A);
	void readFromFile(string fileName);
	void addValue(int value);
	Node * deleteValue(int value);
};