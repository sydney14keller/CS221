#include "ListSL.h"
ListSL::ListSL()
{
	m_length = 0;
	m_current = nullptr;
	m_first = nullptr;
}

void ListSL::resetIterator()
{
	m_current = m_first;
}

ItemSL ListSL::getNext()
{
	//Post: return the current item
	//			update the current/increment it
	if (m_current == nullptr)	{

		m_current = m_first;
	}
	else
	{
		m_current = m_current->m_next;
	}
	return m_current->m_info;
}

bool ListSL::hasNext()
{
	//true if current is not the last item in the list.
	if (m_current->m_next == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ListSL::~ListSL()
{
	clearList();
}

void ListSL::clearList()
{
	//
}


bool ListSL::addItem(const ItemSL& item)  //linked List
{
	if (isFull())
	{
		return false;
	}
	Node* newNode = new Node(item);
	newNode->m_next = m_first;
	m_first = newNode;
	m_length++;

	return true;
}

bool ListSL::removeItem(ItemSL& item)
{
	if (!isEmpty())
	{
		Node* head = m_first;
		Node* tail = nullptr;
		while (item.compareTo(head->m_info) != 0)
		{
			tail = head;
			head = head->m_next; // *head.m_next;
		}
		if (head == m_first)
		{
			m_first = m_first->m_next; //*m_first.next
		}
		else
		{
			tail->m_next = head->m_next;
		}
		delete head;
		m_length--;
		return true;
	}
	return false;
}


bool List::isFull()
{
	if (m_length == MAX_SIZE)
	{
		return true;
	}
	else
		return false;
}
int List::getLength()
{
	return m_length;
}
bool List::isEmpty()
{
	if (m_length == 0)
	{
		return true;
	}
	else
		return false;
}

ItemSL ListSL::getItem(ItemSL& item, bool& found)
{
	resetIterator();
	while (hasNext())
	{
		found = false;
		Item i2 = getNext();
		if (i2.compareTo(item) == 0)
		{
			found = true;
			return i2;
		}
	}
	return item;

}

void ListSL::display(ostream& out)
{
	resetIterator();
	while (hasNext())
	{
		m_current->m_info.display(out);
		getNext();
		cout << endl;
	}
	m_current->m_info.display(out);
}