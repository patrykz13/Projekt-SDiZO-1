#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>

Node * BinarySearchTree::getRoot()
{
	return root;
}

BinarySearchTree::BinarySearchTree(){

	root = NULL;
	size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	removeTree(root);
}
void BinarySearchTree::removeTree(Node* node)
{
	if (node)
	{
		removeTree(node->left);
		removeTree(node->right);
		delete node;
	}
}
int BinarySearchTree::getSize()
{
	return size;
}

void BinarySearchTree::createRandomTree(int numberOfValues)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, numberOfValues);
	removeTree(root);
	root = nullptr;
	size = 0;
	for (int i = 0; i<numberOfValues; i++)
	{
		addValue(dist(gen));
	}

}

Node * BinarySearchTree::searchForValue(Node * p, int k)
{
	while (p && p->data != k)
		p = (k < p->data) ? p->left : p->right;

	return p;
}

void BinarySearchTree::printBT(string sp, string sn, Node * v)
{
	string s;

	if (v)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, v->right);

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->data << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, v->left);
	}
}

Node * BinarySearchTree::predecessor(Node * node)
{
	Node * r;

	if (node)
	{
		if (node->left) return maxNode(node->left);
		else
		{
			r = node->up;
			while (r && (node == r->left))
			{
				node = r;
				r = r->up;
			}
			return r;
		}
	}
	return node;
}

Node * BinarySearchTree::successor(Node * node)
{
	Node * r;

	if (node)
	{
		if (node->right) return minNode(node->right);
		else
		{
			r = node->up;
			while (r && (node == r->right))
			{
				node = r;
				r = r->up;
			}
			return r;
		}
	}
	return node;
}

Node * BinarySearchTree::minNode(Node*root)
{
	if (root) while (root->left) root = root->left;

	return root;
}

Node * BinarySearchTree::maxNode(Node*root)
{
	if (root) while (root->right) root = root->right;

	return root;
}




void BinarySearchTree::addValue(int value)
{
	Node *node;
	size++;
	Node* w = new Node();

	w->left = w->right = NULL;
	w->data = value;

	node = root;

	if (!node)
		root = w;
	else
		while (true)
			if (value < node->data)
			{
				if (!node->left)
				{
					node->left = w;
					break;
				}
				else node = node->left;
			}
			else
			{
				if (!node->right)        // Jeœli prawego syna nie ma,
				{
					node->right = w;      // to wêze³ w staje siê prawym synem
					break;             // Przerywamy pêtlê while
				}
				else node = node->right;
			}

	w->up = node;
}

Node * BinarySearchTree::deleteValue(int value)
{
	size--;
	return deleteNode(searchForValue(root,value));
}



Node * BinarySearchTree::deleteNode(Node * node)
{
	Node * nodeB, *nodeC;

	if (node)
	{
		if(!node->left || !node->right)
		{
			nodeB = node;
		}
		else nodeB = successor(node);
		if(nodeB->left)
		{
			nodeC=nodeB->left;
		}
		else nodeC=nodeB->right;
		if(nodeC)
		{
			nodeC->up = nodeB->up;
		}
		if (!nodeB->up) 
		{
			root = nodeC;
		}
		else if (nodeB == nodeB->up->left) {
			nodeB->up->left = nodeC;
		}
		else nodeB->up->right = nodeC;
		if (nodeB != node) node->data = nodeB->data;
		
		delete nodeB;

	}
	return node;
}




unsigned log2(unsigned x)
{
	unsigned y = 1;

	while ((x >>= 1) > 0) y <<= 1;

	return y;
}
void BinarySearchTree::rebalanceDSW()
{
	unsigned n, i, s;
	Node * p;

	n = 0;
	p = root;
	while (p)
		if (p->left)
		{
			rotateRight(p);
			p = p->up;
		}
		else
		{
			n++;
			p = p->right;
		}
	// Teraz z listy tworzymy drzewo BST
	s = n + 1 - log2(n + 1);

	p = root;
	for (i = 0; i < s; i++)
	{
		rotateLeft(p);
		p = p->up->right;
	}

	n = n - s;

	while (n > 1)
	{
		n >>= 1;
		p = root;
		for (i = 0; i < n; i++)
		{
			rotateLeft(p);
			p = p->up->right;
		}
	}
}

Node * BinarySearchTree::doTurnRight(int value)
{
	if(searchForValue(root, value)!=nullptr)
	{
		rotateRight(searchForValue(root, value));
		return searchForValue(root, value);
	}
	else return nullptr;
	
	
}

Node * BinarySearchTree::doTurnLeft(int value)
{
	if (searchForValue(root, value) != nullptr)
	{
		rotateLeft(searchForValue(root, value));
		return searchForValue(root, value);
	}
	else return nullptr;
}


void BinarySearchTree::rotateLeft(Node * nodeA)
{
	Node * nodeB = nodeA->right, *p = nodeA->up;

	if (nodeB)
	{
		nodeA->right = nodeB->left;
		if (nodeA->right) nodeA->right->up = nodeA;

		nodeB->left = nodeA;
		nodeB->up = p;
		nodeA->up = nodeB;

		if (p)
		{
			if (p->left == nodeA) p->left = nodeB; else p->right = nodeB;
		}
		else root = nodeB;
	}
}


void BinarySearchTree::rotateRight(Node * nodeA)
{
	Node * nodeB = nodeA->left, *p = nodeA->up;

	if (nodeB)
	{
		nodeA->left = nodeB->right;
		if (nodeA->left) nodeA->left->up = nodeA;

		nodeB->right = nodeA;
		nodeB->up = p;
		nodeA->up = nodeB;

		if (p)
		{
			if (p->left == nodeA) p->left = nodeB; else p->right = nodeB;
		}
		else root = nodeB;
	}
}

void BinarySearchTree::readFromFile(string fileName)
{
	string val;
	string size_t;
	ifstream file(fileName);
	if (file.is_open())
	{
		file >> size_t;
		removeTree(root);
		root = nullptr;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else
			for (int i = 0; i <std::stoi(size_t); i++)
			{
				file >> val;
				if (file.fail())
				{
					cout << "File error - READ DATA" << endl;
					break;
				}
				else
					addValue(std::stoi(val));
			}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

