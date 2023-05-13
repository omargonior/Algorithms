#include <iostream>
using namespace std;

template <class T>
class node
{
public:
	T data;
	node<T>* link;
	node() {	data = 0; link = NULL; }
};

template <class T>
class Queue 
{
public:
	T first() const;
	T last() const;
	int getLength() { return length; }
	Queue(int maxq) { front = rear = NULL;  length = 0; MaxSize = maxq; }
	~Queue();
	bool isEmpty() { return front == NULL; }
	bool isFull();
	void display();
	void clear();
	Queue<T>& enQueue(T& item);
	Queue<T>& deQueue(T& item);
	Queue<T>& Add(const T& x);
	bool isFound(T& item);
	void twoqueus(Queue<T>& x, T y[]);
	T Sum();

private:
	node<T>* queue;
	T front;
	T rear;
	int MaxSize;
	int length;
};
/*
template<class t>
void linked<t>::merge(linked<t>& other)
{
	length = length + other.getlength();
	node<t>* ptr = head;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = other.head;
}
*/

template<class T>
Queue<T>& Queue<T>::Add(const T& x) {
	// Add x to the rear of the queue.  Throw NoMem exception if the queue is full.
	//if (IsFull()) throw NoMem();
	rear = (rear + 1) % MaxSize;
	queue[rear] = x;
	length++;
	return *this;
}

//template <class T>
//Queue<T>::~Queue()
//{
//	node<T>* next;
//	while (front)
//	{
//		next = front->link;
//		delete front;
//		front = next;
//	}
//}

template <class T>
void Queue<T>::display()
{
	node<T>* ptr = front;
	cout << "The Queue : ";
	while (ptr)
	{
		cout << ptr->data << "  ";
		ptr = ptr->link;
	}
	cout << endl;
}


template <class T>
T Queue<T>::Sum()
{
	node<T>* ptr = front;
	T sum = 0;
	if (isEmpty())
		return sum;
	else
	{
		while (ptr)
		{
			sum = sum + ptr->data;
			ptr = ptr->link;
		}
		return sum;
	}

}

template <class T>
T Queue<T>::first()const
{
	if (isEmpty())
		return -1;
	else
		return front->data;
}


template <class T>
T Queue<T>::last()const
{
	if (isEmpty())
		return -1;
	else
		return rear->data;
}

template <class T>
Queue<T>& Queue<T>::enQueue(T& item)
{
	node<T>* newNode = new node<T>;
	newNode->data = item;
	if (isEmpty())
		front = rear = newNode;
	else
	{
		rear->link = newNode;
		rear = newNode;
	}
	length++;
	return *this;
}

template<class T>
void Queue<T> ::twoqueus(Queue<T>& x, T y[]) {
	node<T>* ptr = front;
	node<T>* ptr2 = x.front;

	int arrsize = length + x.length;
	if (isEmpty())
	{
		for (int j = 0; j < x.length; j++)
		{
			y[j] = x.front->data;
			ptr2 = ptr2->link;
		}
	}
	else	
	{
	}
	int i = 0;
	for (i; i < length; i++)
	{
		y[i] = ptr->data;
		ptr = ptr->link;
	}
	for (int j = 0; j < x.length;  j++)
	{
		y[i] = x.front->data;
		i++;
		ptr2 = ptr2->link;

	}
	for (x = 0;x < arrsize;x++)
	{
		cout<<arr[x]<<" ";
}
}
template <class T>
Queue<T>& Queue<T>::deQueue(T& item)
{
	if(isEmpty())
		cout << "This is an empty queue ! \n";
	
	else 
	{
		item = front->data;
		node<T>* delp = front;
		if (front == rear)
			front = rear = NULL;
		else
			front = front->link;
		delete delp;
		length--;
		cout << "This is the item had dequeue : "<<item<<" \n";
	}
	return*this;
}

template <class T>
bool Queue<T>::isFound(T& item)
{
	bool found = false;
	if (isEmpty())
		cout << "This is an empty queue ! \n";
	else
	{
		node<T>* ptr = front;
		while (ptr)
		{
			if (ptr->data==item)
				found = true;
			ptr = ptr->link;
		}
	}
	return found;
}