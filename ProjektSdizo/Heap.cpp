#include "Heap.h"
#include <iostream>
#include <ctime>
#include<string>
#include<fstream>
#include <vector>
#include <random>
using namespace std;
Heap::Heap()
{
	srand(time(nullptr));
	heapArray = new int[0];
	size = 0;
}
Heap::~Heap()
{
	delete[]heapArray;
	heapArray = nullptr;

}
	
int Heap::getSize()
{
	return size;
}


void Heap::createRandomHeap(int numberOfValues)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, numberOfValues);
	delete[]heapArray;
	int value;
	heapArray = nullptr;
	size = 0;
	heapArray = new int[numberOfValues];
	for (int z = 0; z<numberOfValues; z++)
	{
		value = dist(gen);
		int i, j;
		i = size++;
		j = (i - 1) / 2; //indeks rodzica

		while (i > 0 && heapArray[j]< value)
		{
			heapArray[i] = heapArray[j];
			i = j;
			j = (i - 1) / 2;

		}

		heapArray[i] = value;
	}
	
}

void Heap::addValue(int value)
{
	

	int * tmp = new int[size+1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = heapArray[i];
	}
	delete[] heapArray;
	heapArray = tmp;

	int i, j;
	i = size++;
	j = (i - 1) / 2; //indeks rodzica

	while (i > 0 && heapArray[j]< value) //warunek kopca 
	{
		heapArray[i] = heapArray[j];
		i = j;
		j = (i - 1) / 2;

	}

	heapArray[i] = value;
}

void Heap::deleteFromTheBotton()
{
	int i, j, v;
	
	if(size==0)
	{
		std::string exception = "Kopiec jest pusty";
		throw exception;
	}
	if (size--)
	{
		v = heapArray[size];

		i = 0;
		j = 1;

		while (j < size) //idziemy w dol kopca
		{
			if (j + 1 < size && heapArray[j + 1] > heapArray[j]) j++; //szukamy wiekszego syna
			if (v >= heapArray[j]) break;
			heapArray[i] = heapArray[j]; //przenosimy wiekszego syna do ojca
			i = j; // skok na indeks wiekszego syna
			j = 2 * j + 1; //indeks lewego syna
		}

		heapArray[i] = v;
	}
	// alokcja nowej tablicy
	int * tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = heapArray[i];
	}
	delete[] heapArray;
	heapArray = tmp;
}

int Heap::searchForValue(int value)
{
	int index = 0;
	bool found = false;
	while ((!found) && (index < size))
		if (value == heapArray[index])
			found = true;
		else
			index++;

	if (found)
		return index;
	else
		return -1;

}

void Heap::printHeap(string sp, string sn, int v)
{
	string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printHeap(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << heapArray[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printHeap(s + cp, cl, 2 * v + 1);
	}
}


void Heap::printAll()
{
	for (int i = 0; i<size; i++)
	{
		cout << "Heap element " << i << ". key= " << heapArray[i] << "    ";
	}

	cout << size;
}

void Heap::readFromFile(string fileName)
{
	string val;
	string size_t;
	ifstream file(fileName);
	if (file.is_open())
	{
		file >> size_t;
		std::stoi(size_t);
		delete heapArray;
		heapArray = new int[0];
		size = 0;
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

std::string do_padding(unsigned index, unsigned mlength) {
	std::string padding;
	if (int((index - 1) / 2) != 0) {
		return (int((index - 1) / 2) % 2 == 0) ?
			(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
			(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
	}
	return padding;
}

void printer(std::vector<int> const & tree, unsigned index, unsigned mlength) {
	auto last = tree.size() - 1;
	auto  left = 2 * index + 1;
	auto  right = 2 * index + 2;
	std::cout << " " << tree[index] << " ";
	if (left <= last) {
		auto llength = std::to_string(tree[left]).size();
		std::cout << "---" << std::string(mlength - llength, '-');
		printer(tree, left, mlength);
		if (right <= last) {
			auto rlength = std::to_string(tree[right]).size();
			std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
			std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " *" <<
				std::string(mlength - rlength, '-');
			printer(tree, right, mlength);
		}
	}
}


void Heap::print_tree() {
	vector<int> tree(heapArray, heapArray + size);
	unsigned mlength = 0;
	for (int & element : tree) {
		auto clength = std::to_string(element).size();
		if (clength > mlength) {
			mlength = std::to_string(element).size();
		}
	}
	std::cout << std::string(mlength - std::to_string(tree[0]).size(), ' ');
	printer(tree, 0, mlength);
}

