#pragma once
class Array
{
private:
	int size;
	int* array;
public:
	Array();
	~Array();
	int getSize();
	void createRandomArray(int numberOfValues);

	void addAtTheEnd(int value);

	void addAtTheBeginning(int value);

	void addToRandomPlace(int value,int randomPlace);

	void deleteValue(int value);

	int searchForValue(int value);

	void showArray();

	void readFromFile(std::string fileName);
	
	void deleteFromRandomPlace(int randomPlace);

	void deleteFromTheBeginning();

	void deleteFromTheEnd();
	

};