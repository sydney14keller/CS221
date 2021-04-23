

#include "ItemSL.h"

#define MAX_SIZE 10

class ListSL
{

public:
	//page 146
	ListSL();
	~ListSL();
	void clearList();
	bool addItem(ItemSL& i);
	bool removeItem(ItemSL& item);
	bool isFull();
	int getLength();
	bool isEmpty();
	ItemSL getItem(ItemSL& item, bool& found);

	void resetIterator();
	bool hasNext();
	ItemSL getNext();
	void display(ostream& out);

private:
	int m_length;
	int m_current;
	//an array of Items
	ItemSL info[MAX_SIZE];
};
