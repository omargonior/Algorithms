#include <iostream>
using namespace std;
//stack using linkedlist
template <class T>
class node
{
public:
	T data;
	node<T>* link;
	node() 
	{
		data = 0;
		link = NULL;
	}
};


template <class T>
class stack
{
public:
	stack() { top = NULL;length = 0; }
	~stack();
	bool isEmpty() { return top == NULL; }
	int getLength() { return length; }
	stack<T>& push(T& item);
	stack<T>& pop();
	T& peek() {	return top->data; }
	bool find(int index, T& value);
	int search(T&);
	void display();
	void doubleStack(stack<T>* other);
	bool balanced_parentheses(string expr);
private:
	node<T>* top;
	int length;
};

template <class T>
stack<T>::~stack()
{
	node<T>* next;
	while (top)
	{
		next = top->link;
		delete top;
		top = next;
	}
}

template <class T>
stack<T>& stack<T>::push(T& item)
{
	node<T>* newNode=new node<T>;
	newNode->data = item;
	if (isEmpty())
	{
		top = newNode;
	}
	else
	{
		newNode->link = top;
		top = newNode;
	}
	length++;
	return *this;
}

template <class T>
stack<T>& stack<T>::pop()
{
	if (isEmpty())
		cout << "this is empty stack" << endl;
	else
	{
		T value=top->data;
		node<T>* delp=top;
		top = top->link;
		delete delp;
		cout << "the value you have delete is : " << value<<endl;
		length--;
	}
	return *this;
}

template <class T>
void stack<T>::display()
{
	if (isEmpty())
		cout <<"this is empty stack" << endl;
	else {
		node<T>* ptr = top;
		while (ptr)
		{
			cout << ptr->data << " ";
			ptr = ptr->link;
		}
		cout << endl;
	}
}



template <class T>
bool stack<T>::balanced_parentheses(string exp)
{
	for (int i = 0;i < exp.length();i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (isEmpty())return false;
			else if (peek() == '(' && exp[i] == ')' ||
					 peek() == '{' && exp[i] == '}' ||
					 peek() == '[' && exp[i] == ']' ) pop();
			else return false;
		}
	}
	return true;
}



template<class T>
bool stack<T>::find(int index, T& value)
{
	bool found = false;
	if (isEmpty())
	{
		cout << "empty stack !" << endl;
		return found;
	}
	else {
		node<T>* ptr = top;
		int counter = 1;
		while (index > counter && ptr  )
		{
			ptr = ptr->link;
			counter++;
		}
		if (counter == index && ptr )
		{
			value = ptr->data;
			found = true;
		}
		return found;
	}
}


template <class T>
int stack<T>::search(T& value)
{
	int bosition = -1;
	if (isEmpty())
	{
		cout << "empty stack !" << endl;
		return bosition;
	}
	else
	{
		node<T>* ptr = top;
		int counter = 1;
		while (ptr)
		{
			if (ptr->data == value)
			{
				bosition = counter;
				break;
			}
			ptr = ptr->link;
			counter++;
		}
		return bosition;
	}
}
