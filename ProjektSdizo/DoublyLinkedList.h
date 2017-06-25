struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class DoublyLinkedList
{
private:
	node *head;
	node*tail;
	int numberOfElements;
public:

	int getNumberOfElements();
	DoublyLinkedList();
	~DoublyLinkedList();
	void createRandomList(int numberOfValues);
	void addAtTheBeginning(int data);
	void addAtTheEnd(int data);
	void addToRandomPlace(int value,int randomPlace);
	void deleteFromRandomPlace(int randomPlace);
	void removeElement(node * e);
	void deleteFromTheBeginning();
	void deleteFromTheEnd();
	int searchForValue(int value);	
	void showList();
	void readFromFile(std::string fileName);
	
};
