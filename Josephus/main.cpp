#include <iostream>
#define nullptr NULL

using namespace std;


class Node {
public:
	int Data;
	Node* Next;

	Node(int Data, Node* Next)
	{
		this->Data = Data;
		this->Next = Next;
	}
};

class CircularLinkedList {
public:
	Node* Tail;
	int Size;

public:
	CircularLinkedList();
	~CircularLinkedList();
	bool isEmpty();
	void push(int data);
	void remove(Node* pivot);
	void clear();
};

int salveJosephus(int n, int m);

CircularLinkedList::CircularLinkedList()
{
	this->Tail = nullptr;
	this->Size = 0;
}

CircularLinkedList::~CircularLinkedList()
{
	clear();
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

	circularList->push(1);
	for (int i = n; i > 1; i--)
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
		//	cout << pivot->Data << endl;
		if (circularList->Size == 1)
			return pivot->Data;
		pivot = pivot->Next;
	}
	circularList->~CircularLinkedList();
}

int main()
{
	cout << salveJosephus(, ) << endl;

}