#include <iostream>
#include <time.h>       /* time */
#include "Array.h"
#include <fstream>
#include <string>
#include <random>

using namespace std;
	
	Array::Array(){
		array = new int[0];
		size = 0;
	}

	Array::~Array()
	{
		delete[]array;
		array = nullptr;
	}

	int Array::getSize()
	{
		return size;
	}

	void Array::createRandomArray(int numberOfValues)
	{
		delete[]array;
		array = nullptr;
		size = 0;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(0, numberOfValues);
		array = new int[numberOfValues];
		size = numberOfValues;
		for(int i =0;i<numberOfValues;i++)
		{
			array[i] = dist(gen);
		}
	}

	void Array::addAtTheEnd(int value)
	{
		size = size + 1;
		int * tmp = new int[size];
		for (int i = 0; i < size-1; i++)
		{
			tmp[i] = array[i];
		}
		delete[] array;
		array = tmp;
		array[size - 1] = value;
	}

	void Array::addAtTheBeginning(int value)
	{
		size = size + 1;
		int * tmp = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			tmp[i+1] = array[i];
		}
		delete[] array;
		array = tmp;
		array[0] = value;
	}

	void Array::addToRandomPlace(int value,int randomPlace)
	{
		size = size + 1;
		int * tmp = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			tmp[i] = array[i];
		}
		for (int i =size-2; i>=randomPlace ; i--)
		{
			tmp[i+1] = tmp[i];

		}
		delete[] array;
		array = tmp;
		array[randomPlace] = value;
	}

	void Array::deleteValue (int value) {

		for (int i = 0; i < size; i++)
		{
			if(array[i]==value)
			{
				for (int j = 0; j < size-1; j++)
				{
					array[j] = array[j + 1];
				}
				size = size - 1;
				int * tmp = new int[size];
				for (int j = 0; j < size; j++)
				{
					tmp[j] =array[j];
				}
				delete[]array;
				array = tmp;
			}
		}

	}

	int Array::searchForValue(int value)
	{
		int index = 0;
		bool found = false;
		while ((!found) && (index < size))
			if (value == array[index])
				found = true;
			else
				index++;

		if (found)
			return index;
		else
			return -1;
	}

	void Array::showArray()
	{
		if(size!=0)
		{
			for (int i = 0; i<size; i++)
			{
				cout << array[i] << "  ";
			}
		}
		else { cout << "Tablica jest pusta " << endl; }
		cout << endl;
	}

	void Array::readFromFile(string fileName)
	{
		string val;
		string size_t;
		ifstream file(fileName);
		if (file.is_open())
		{	
			file >> size_t;
			delete array;
			size = std::stoi(size_t);
			array = new int[size];
			if (file.fail())
				cout << "File error - READ SIZE" << endl;
			else
				for (int i = 0; i < size; i++)
				{
					file >> val;
					if (file.fail())
					{
						cout << "File error - READ DATA" << endl;
						break;
					}
					else
						array[i] = std::stoi(val);
				}
			file.close();
		}
		else
			cout << "File error - OPEN" << endl;
	}

	void Array::deleteFromRandomPlace(int randomPlace)
	{

		for (int j = randomPlace; j < size - 1; j++)
		{
			array[j] = array[j + 1];
		}
		size = size - 1;
		int * tmp = new int[size];
		for (int j = 0; j < size; j++)
		{
			tmp[j] = array[j];
		}
		delete[]array;
		array = tmp;
	}

	void Array::deleteFromTheBeginning()
	{
		
			for (int j = 0; j < size - 1; j++)
			{
				array[j] = array[j + 1];
			}
			size = size - 1;
			int * tmp = new int[size];
			for (int j = 0; j < size; j++)
			{
				tmp[j] = array[j];
			}
			delete[]array;
			array = tmp;
		}

		
	

	void Array::deleteFromTheEnd()
	{

			
			size = size - 1;
			int * tmp = new int[size];
			for (int j = 0; j < size; j++)
			{
				tmp[j] = array[j];
			}
			delete[]array;
			array = tmp;
		
		
	}





//srednia z serii danych
