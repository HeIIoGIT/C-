#include<iostream>
using namespace std;


template<typename T>
class list
{
public:


	list();
	~list();

	void pop_front();
	void pop_back();
	void push_front(T data);
	void push_back(T data);
	int getsize() { return size; }
	void insert(T value, int index);
	void removeAt(int index);
	void clear();
	T& operator[](const int index);

private:


	template<typename T>
	class Node
	{
	public:


		T data;
		Node* next;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}

	};
	Node<T>* head;
	int size;
};


template<typename T>
list<T>::list()
{
	size = 0;
	head = nullptr;
}

template<typename T>
list<T>::~list()
{
	clear();
}


template<typename T>
void list<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}


template<typename T>
void list<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void list<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node<T>(data);
	}
	size++;
}


template<typename T>
void list<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* newNode = new Node<T>(data, previous->next);
		previous->next = newNode;
		size++;
	}
}


template<typename T>
void list<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;
		size--;
	}
}


template<typename T>
void list<T>::clear()	//auto
{
	while (size)
	{
		pop_front();
	}
}


template<typename T>
T& list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}




int main()
{
	list<int> lst;

	int numbersCount;
	cout << "Enter to count numbers: ";
	cin >> numbersCount;

	for (int i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 10);
	}

	cout << "NodeList:\n";

	for (int i = 0; i < lst.getsize(); i++)
	{
		cout << "\n[" << i << "] - " << lst[i];
	}

	cout << "\n\n[10] - " << lst[10] << endl;

	lst.pop_front();
	lst.pop_back();
	lst.push_front(100);
	lst.push_back(200);
	lst.removeAt(10);
	lst.insert(150, 10);

	for (int i = 0; i < lst.getsize(); i++)
	{
		cout << "\n[" << i << "] - " << lst[i];
	}

	cout << endl;

	return 0;
}