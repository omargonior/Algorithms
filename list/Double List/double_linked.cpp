#include <iostream>
using namespace std;

template <class T>
class doubleNode
{
public:
	T data;
	doubleNode<T>* rightLink;
	doubleNode<T>* leftLink;
	doubleNode()
	{
		data = 0;
		rightLink = leftLink = NULL;
	}
};


template <class T>
class doublyLinked 
{
public:
	doublyLinked() { 
	head = NULL; 
	tail = NULL; 
	length = 0; }
	~doublyLinked() { erase(); }
	void erase();
	void display();
	bool isEmpty() { return head == NULL; };
	int getlength() { return length; }
	doublyLinked<T>& insertFirst(T& item);
	doublyLinked<T>& insertAfter(int index,T& item);
	doublyLinked<T>& DELETE(int index, T& value);
	bool find(int index, T& value);
	int search(T& value);
	bool sorted();
	T& min_second();
	void median();
	doubleNode<T>* head;
	doubleNode<T>* tail;
	int length;
};

template<class T>
void doublyLinked<T>::erase()
{
	doubleNode<T>* ptr;
	while (head != NULL)//length!=0 //tail->link!=head if circuler
	{
		ptr = head->rightLink;
		delete head;
		//head->leftLink = NULL;
		head = ptr;
		length--;
	}
}


template<class T>
bool doublyLinked<T>::find(int index, T& value)
{
	bool found = false;
	if (isEmpty())
	{
		cout << "empty list !" << endl;
		return found;
	}
	else {
		doubleNode<T>* ptr = head;
		int counter = 1;
		while (index > counter && ptr)
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

template<class T>
int doublyLinked<T>::search(T& value)
{
	int index = -1;
	if (isEmpty())
	{
		cout << "empty list !" << endl;
		return index;
	}
	else
	{
		doubleNode<T>* ptr = head;
		int counter = 1;
		while (ptr )
		{
			if (ptr->data == value)
			{
				index = counter;
				break;
			}
			ptr = ptr->rightLink;
			counter++;
		}
		return index;
	}
}



template<class T>
doublyLinked<T>& doublyLinked<T>::DELETE(int index, T& value)
{
	if (index < 0)
	{
		cout << "the index must be >0 " << endl;
		return *this;
	}
	if (isEmpty())
	{
		cout << "empty list !" << endl;
		return *this;

	}

	doubleNode<T>* ptr = NULL, * delp = head;
	int conter = 1;
	while (conter < index && delp)
	{
		ptr = delp;
		delp = delp->rightLink;
		conter++;
	}
	if (conter == index)
	{
		value = delp->data;
		if (head == delp)
			head = head->rightLink;

		else if (delp == tail)
		{
			tail = ptr;//tail=delp->leftLink;
			ptr->rightLink = NULL;
		}
		else 
		{
			doubleNode<T>* temp=delp->rightLink;
			ptr->rightLink = temp;
			temp->leftLink = ptr;
		}
		delete delp;
		cout << "the value you have delete =  " << value << endl;
		cout << "the value in the head  =  " << head->data << endl;
		cout << "the value in the tail =  " << tail->data << endl;
		length--;
	}
	return *this;
}



template<class T>
void doublyLinked<T>::median()
{
	doubleNode<T>* ptr = head;
	for (int i = 1;i < getlength() / 2;i++)
	{
		ptr = ptr->rightLink;
	}
	if (getlength() % 2 != 0)
	{
		cout << " the median of this list is in the node number " << (getlength() / 2) + 1 << "\n and the median ="<<ptr->rightLink->data<<"\n";
	}
	else
	{
		cout << " the median of this list is the avrege of  the node number " << getlength() / 2<< " and "<< (getlength() / 2) + 1 << "\n and the median =" <<float(ptr->data +ptr->rightLink->data ) / 2<< "\n";

	}
}


template<class T>
T& doublyLinked<T>::min_second()
{
	T secMin = -1;
	T fmin = head->data;
	doubleNode<T>* temp = head;
	if(isEmpty())
	{
		secMin = 0;
		return secMin;
	}
	else if (getlength() >= 2)
	{
		while (temp)
		{
			if (temp->data < fmin)
				fmin = temp->data;

			temp = temp->rightLink;
		}

		temp = tail;
		if (head->data > fmin)
			secMin = head->data;
		else
			secMin = tail->data;
		while (temp)
		{
			if (temp->data < secMin && temp->data != fmin)
				secMin = temp->data;

			temp = temp->leftLink;
		}
		return secMin;
	}

	else
		return secMin;
	
}

template<class T>
bool doublyLinked<T>::sorted()
{
	bool isSorted = false;
	doubleNode<T>* ptr = head;
	doubleNode<T>* prev = NULL;
	if (ptr)
	{
		prev = ptr;
		ptr = ptr->rightLink;
	}
	while (ptr)
	{
		if (prev->data <= ptr->data)
			isSorted = true;
		else 
			isSorted = false;
		prev = ptr;
		ptr = ptr->rightLink;
	}
	return isSorted;
}



template<class T>
doublyLinked<T>& doublyLinked<T>::insertFirst(T& item)
{
	doubleNode<T>* newNode = new doubleNode<T>;
	newNode->data = item;
	if(isEmpty())
		head = tail = newNode;
	else
	{
		newNode->rightLink = head;
		head->leftLink = newNode;
		head = newNode;
		//if circular tail->rightLink=head;
	}
	length++;
	return*this;
}

template<class T>
doublyLinked<T>& doublyLinked<T>::insertAfter(int index, T& item)
{
	if (isEmpty())
	{
		cout << "this is an empty list ! \n if you want to insert this item first answer 'y'\n if not answer 'n' \n ";
		char answer;
		cin >> answer;
		switch (answer)
		{
		case'y':
			insertFirst(item);
			break;
		default:
			break;
		}
	}
	else
	{
		if (index < 0)
		{
			cout << "the index must be >0 " << endl;
		}
		doubleNode<T>* newNode = new doubleNode<T>;
		newNode->data = item;
		doubleNode<T>* ptr = head;
		int counter = 1;
		while (counter < index && ptr)
		{
			ptr = ptr->rightLink;
			counter++;
		}
		if (counter == index && ptr)
		{
			newNode->rightLink = ptr->rightLink;
			newNode->leftLink = ptr;
			ptr->rightLink = newNode;
			ptr = newNode;
			if (ptr->rightLink == NULL)
				tail = newNode;
			length++;
			cout << "the value in the head  =  " << head->data << endl;
			cout << "the value in the tail =  " << tail->data << endl;
		}
	}
	return*this;
}

template <class T>
void doublyLinked<T>::display()
{
	if (isEmpty())
		cout << "empty list !" << endl ;
	else
	{
		cout << "Desplaying the  list : " << endl;

		doubleNode<T>* temp = head;
		while (temp)
		{
			cout << temp->data << "  ";
			temp = temp->rightLink;
		}
		cout << endl;

	}
}