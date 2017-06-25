#include<iostream>
#include "DoublyLinkedList.h"
#include <ctime>
#include <string>
#include <fstream>
#include <random>

using namespace std;

int DoublyLinkedList::getNumberOfElements()
{
	return numberOfElements;
}

DoublyLinkedList::DoublyLinkedList()
{
	head = tail = NULL;
	numberOfElements = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	node * element;
	while (head!=nullptr)
	{
		element = head->next;
		delete head;
		head = element;
	}
	numberOfElements = 0;
}

void DoublyLinkedList::createRandomList(int numberOfValues)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, numberOfValues);
	node * element;
	while (head != nullptr)
	{
		element = head->next;
		delete head;
		head = element;
	}
	head = tail = NULL;
	numberOfElements = 0;
	for (int i = 0; i<numberOfValues; i++)
	{
		addAtTheEnd(dist(gen));
	}
}

void DoublyLinkedList::addAtTheBeginning(int data)
{
	node * newElement;

	newElement = new node;   // tworzymy nowy element
	newElement->data = data;
	newElement->prev = NULL;
	newElement->next = head;
	head = newElement;
	numberOfElements++;
	if (newElement->next) newElement->next->prev = newElement;
	else tail = newElement;
}
void DoublyLinkedList::addAtTheEnd(int value)
{
	node * newElement = new node();
	newElement->data = value;
	newElement->next = NULL;
	newElement->prev = tail;
	tail = newElement;
	numberOfElements++;
	if (newElement->prev) newElement->prev->next = newElement;
	else head = newElement;
}

void DoublyLinkedList::addToRandomPlace(int value,int randomPlace)
{
	node * element;
	if(randomPlace <(numberOfElements-1)/2)
	{
		int i = 0;
		element = head;
		while (element != NULL)
		{
			if (i == randomPlace) break;
			element = element->next;
			i++;
		}
	}
	else
	{
		int i = numberOfElements - 1;
		element = tail;
		while (element != NULL)
		{
			if (i == randomPlace) break;
			element = element->prev;
			i--;
		}
	}
	

	if (element == tail) addAtTheEnd(value);
	else if (element == head)addAtTheBeginning(value);
	else
	{
		node * new_element = new node();
		new_element->data = value;
		new_element->next = element->next;
		new_element->prev = element;
		numberOfElements++;
		element->next->prev = new_element;
		element->next = new_element;
	}


}

void DoublyLinkedList::deleteFromRandomPlace(int randomPlace)
{
	node * element;
	if(numberOfElements)
	{
		if (randomPlace <(numberOfElements - 1) / 2)
		{
			int i = 0;
			element = head;
			while (element != NULL)
			{
				if (i == randomPlace) break;
				element = element->next;
				i++;
			}
		}
		else
		{
			int i = numberOfElements - 1;
			element = tail;
			while (element != NULL)
			{
				if (i == randomPlace) break;
				element = element->prev;
				i--;
			}
		}
		numberOfElements--;
		if (element->prev) element->prev->next = element->next;
		else        head = element->next;
		if (element->next) element->next->prev = element->prev;
		else        tail = element->prev;
		delete element;

	}
	

}

void DoublyLinkedList::removeElement(node * e)
{
	numberOfElements--;
	if (e->prev) e->prev->next = e->next;
	else        head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        tail = e->prev;
	delete e;
}

void DoublyLinkedList::deleteFromTheBeginning()
{
	if (numberOfElements) removeElement(head);

}

void DoublyLinkedList::deleteFromTheEnd()
{
	if (numberOfElements) removeElement(tail);

}

int DoublyLinkedList::searchForValue(int value)
{
	node * element;
	node *element2;
	element = head;
	element2 = tail;
	int i = 0;
	while (element != NULL &&element2!=NULL)
	{																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										
		if (element->data == value) return value;
		element = element->next;

		if (element2->data == value) return value;
		element = element2->next;

		i++;
	}
	return -1;
}

void DoublyLinkedList::showList()
{
	node * element = new node();
	int i = 1;
	if (!head) cout << "Lista jest pusta." << endl;
	else
	{
		element = head;
		while (element)
		{
			cout << element->data << "  ";
			element = element->next;
			i++;
		}
		cout << endl;

	}
}

void DoublyLinkedList::readFromFile(string fileName)
{
	string val;
	string size_t;
	ifstream file(fileName);
	if (file.is_open())
	{
		file >> size_t;
		node * element;
		while (head != nullptr)
		{
			element = head->next;
			delete head;
			head = element;
		}
		head = tail = NULL;
		numberOfElements = 0;
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
				addAtTheEnd(std::stoi(val));
			}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

