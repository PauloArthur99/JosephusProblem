#include "LinkedList.h"
#include <iostream>

using namespace std;

CircularLinkedList::CircularLinkedList()
{
	this->Tail = nullptr;
	this->Size = 0;
}

CircularLinkedList::~CircularLinkedList()
{
	clear();
}

int CircularLinkedList::len()
{
	return this->Size;
}

bool CircularLinkedList::isEmpty()
{
	return this->Size == 0;
}

void CircularLinkedList::push(int data)
{
	Node* new_node;
	new_node = new Node(data, nullptr);

	if (this->isEmpty())
	{
		this->Tail = new_node;
		(this->Tail)->Next = this->Tail;
	}
	else
	{
		new_node->Next = (this->Tail)->Next;
		(this->Tail)->Next = new_node;
	}
	this->Size++;
}

void CircularLinkedList::remove(Node* pivot)
{
	if (this->Size == 0 || this->isEmpty())
	{
		this->Tail = nullptr;
		this->Size = 0;
	}
	else
	{
		Node* t = pivot->Next;
		pivot->Next = (pivot->Next)->Next;
		(this->Size)--;
		delete t;
	}
}

void CircularLinkedList::clear()
{
	Node* t, *p = this->Tail;
	while (p)
	{
		t = p;
		p = p->Next;
		delete t;
	}
	this->Size = 0;
	this->Tail = nullptr;
}

int salveJosephus(int n, int m)
{
	CircularLinkedList* circularList = new CircularLinkedList();
	
	for (int i = 1; i <= n; i++)
	{
		circularList->push(i);
	}

	Node* pivot = circularList->Tail;

	while (circularList->Size > 1)
	{
		int j = 0;
		Node* pivotInit = pivot;

		while (j < m - 1)
		{
			pivot = pivot->Next;
			j++;
		}
		if ((pivot->Next)->Data == pivotInit->Data)
			pivot = pivotInit;

		circularList->remove(pivot);
		pivot = pivot->Next;
	}
}

int main()
{
	cout << salveJosephus(10, 1) << endl;
}