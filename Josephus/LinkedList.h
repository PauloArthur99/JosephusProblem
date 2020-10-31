class CircularLinkedList {
public:
	Node* Tail;
	int Size;

public:
	CircularLinkedList();
	~CircularLinkedList();
	int len();
	Node* get(int data)
	{
		if (this->Tail == nullptr)
			return nullptr;
		Node* pivot;
		pivot = (this->Tail)->Next;
		while (pivot != this->Tail and pivot->Data != data)
			pivot = pivot->Next;
		
		if (pivot->Data != data)
			return nullptr;

		return pivot;
	}
	bool isEmpty();
	void push(int data);
	void remove(Node* pivot);
	void clear();
};

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

int salveJosephus(int n, int m);