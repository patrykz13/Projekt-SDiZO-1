#include <string>

class Heap
{
private:
	int *heapArray;
	int size;

public:
	std::string cr, cl, cp;      // ³añcuchy do znaków ramek
	Heap();
	~Heap();
	int getSize();
	void createRandomHeap(int numberOfValues);
	void addValue(int value);
	void deleteFromTheBotton();
	int searchForValue(int value);
	void printHeap(std::string sp, std::string sn, int v);
	void printAll();
	void readFromFile(std::string fileName);
	void print_tree();
};

