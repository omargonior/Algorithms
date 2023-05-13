#include <iostream>
using namespace std;
//stack using array representation

template <class T>
class stack
{
public:
	stack(const int maxSize);
	~stack() { delete[] items; };
	void display();
	int getSize() { return size; };
	int getLength() { return top+1; };
	int search(const T& x) const;
	bool find(int index, T& value)const;
	bool isEmpty() { return top==-1; }
	stack<T>& push(const T& newItem);
	stack<T>& pop();
	T& peek() { return items[top]; }
	void enLarge(int NEWSIZE);
	void merge(stack<T>& other);
private:
	int size;
	int top;
	T* items;
};

template <class T>
stack<T>::stack(const int maxSize)
{
	top = -1;
	size = maxSize;
	items = new T[size];
}

template <class T>
stack<T>& stack<T>:: push(const T& newItem)
{
	if (top == size)
		cout << "stack is full ! \n";
	else
	{
		top++;
		items[top] = newItem;
	}
	return *this;
}

template <class T>
stack<T>& stack<T>::pop()
{
	if (isEmpty())
		cout << "this is empty stack " << endl;
	else
	{
		T value = items[top];
		top--;
		cout << "the value you have delete is : " << value << endl;
	}
	return *this;
}

template <class T>
void stack<T>::display()
{
	cout << "the items in the stack  : "  << endl;

	for (int i = top;i >= 0;i--)
	{
		cout << items[i] << " , ";
	}
	cout << endl;
}

template <class T>
bool stack<T>::find(int index, T& value)const
{
	if (index <0 || index > size)
		return false;
	else
	{
		value = items[index];
		return true;
	}
}

template <class T>
int stack<T>::search(const T& x) const
{
	int index = -1;
	for (int i = 0;i < top;i++)
	{
		if (items[i] == x)
		{
			index = i;
			break;
		}
	}
	return index;
}

template <class T>
void stack<T>::enLarge(int NEWSIZE)
{
	if (NEWSIZE <= top)
	{
		cout << "sorry, the new size is smaller than the length " << endl;
		return;
	}
	else
	{
		size = NEWSIZE;
		T* old = items;
		items = new T[size];
		for (int i = 0;i <= top;i++)
		{
			items[i] = old[i];
		}
		delete[] old;
	}
}

template <class T>
void stack<T>::merge(stack<T>& other)
{
	size = size + other.getSize();
	T* old = items;
	items = new T[size];
	int i;
	for (i = 0;i < top;i++)
	{
		items[i] = old[i];
	}
	int top1 = top + other.getLength() - 1;
	delete[] old;

	//we well do this as the logic of stack is last in first out 

	for (int j =top;j <=top1;j--)
	{

		items[i++] = other.items[j];
	}


}