#include <iostream>
#include<list>
using namespace std;

template<class t>
class linked;

template<class t>
class node
{
	friend class linked<t>;

	t data;
	node<t> *link;
};
template<class t>
class linked
{
public:
	linked() { head = NULL; };
	~linked() { erase(); };
	void erase();
	bool isEmpty() { return head == NULL; };
	int getlength() { return length; }
	void insertFirst(t& item);
	void display();
	bool find(int index, t& value);
	int search(t& value);
	void Append(t& item);
	void merge(linked<t>& other);
	linked<t>& insertAfter(int index, t& value);
	linked<t>& insertBefore(int index, t& value);
	linked<t>& DELETE(int index, t& value);


private:
	node<t>* head;
	node<t>* tail;
	int length;
};
template<class t>
void linked<t>::erase()
{
	node<t>* ptr;
	while (head!=NULL)//length!=0 //tail->link!=head if circuler
	{
		ptr = head->link;
		delete head;
		head = ptr;
		length--;
	}
}

template<class t>
void linked<t>::insertFirst(t& item)
{
	node<t> *newnode=new node<t>;
	newnode->data = item;
	if (isEmpty())
	{
		newnode->link = NULL;//tail->link=head
		head = tail = newnode;
	}
	else
	{
		newnode->link = head;
		head = newnode;
	}
	length++;
}

template<class t>
void linked<t>::display()
{
	if (isEmpty())
		cout << "empty list !" << endl<<endl;
	else
	{
		node<t>* temp = head;
		while (temp != NULL)
		{
			cout <<temp->data << "  ";
			temp = temp->link;
		}
		cout << endl;

	}
}

template<class t>
bool linked<t>::find(int index, t& value)
{
	bool found = false;
	if (isEmpty())
	{
		cout << "empty list !" << endl;
		return found;
	}
	else {
		node<t>* ptr = head;
		int counter = 1;
		while (index > counter && ptr != NULL)
		{
			ptr = ptr->link;
			counter++;
		}
		if (counter == index && ptr != NULL)
		{
			value = ptr->data;
			found = true;
		}
		return found;
	}
}

template<class t>
int linked<t>::search( t& value)
{
	 int index = -1;
	if (isEmpty())
	{
		cout << "empty list !" << endl;
		return index;
	}
	else
	{
		node<t>* ptr = head;
		int counter = 1;
		while (ptr != NULL)
		{
			if (ptr->data == value)
			{
				index = counter;
				break;
			}
				ptr = ptr->link;
				counter++;
		}
		return index;
	}
}

template<class t>
void linked<t>::Append(t& item)
{
	node<t>* newNode = new node<t>;
	newNode->data = item;
	newNode->link = NULL;//=head if circuler

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		node<t>* ptr=head;
		while (ptr->link!=NULL)//ptr->link!=head if circuler
		{
			ptr = ptr->link;
		}
		if (ptr->link == NULL)
		{
			ptr->link = newNode;
			tail=newNode;
		}
		
	}
	cout << "the value in the head  =  " << head->data << endl ;
	cout << "the value in the tail =  " << tail->data << endl ;
	length++;
}

template<class t>
linked<t>& linked<t>::insertAfter(int index, t& value)
{
	if (index<0)
		cout << "the index must be >0 " << endl;

	node<t> *newNode = new node<t>;
	newNode->data = value;
	node<t>* ptr = head;
	int conter=1;
	while (conter<=index && ptr!=NULL)
	{
		if (conter == index && ptr != NULL)
		{
			newNode->link = ptr->link;
			ptr->link = newNode;
			ptr = newNode;
			if (ptr->link == NULL)
				tail = newNode;
			length++;
			cout << "the value in the head  =  " << head->data << endl ;
			cout << "the value in the tail =  " << tail->data << endl ;
			break;
		}
		
	   ptr = ptr->link;
	   conter++;
	}
	return*this;
}

template<class t>
linked<t>& linked<t>::insertBefore(int index, t& value)
{
	if (index < 0)
	{
		cout << "the index must be >0 " << endl;
	}

	node<t>* newNode = new node<t>;
	newNode->data = value;
	node<t>* ptr = head;
	int conter = 1;
	while (conter<=index && ptr)
	{
		if (index == 1)
		{
			insertFirst(value);
			length++;
			cout << "the value in the head  =  " << head->data << endl ;
			cout << "the value in the tail =  " << tail->data << endl ;
			break;
		}

		if ((conter == index-1)  && ptr)
		{
			newNode->link = ptr->link;
			ptr->link = newNode;
			ptr = newNode;
			length++;
			cout << "the value in the head  =  " << head->data << endl << endl;
			cout << "the value in the tail =  " << tail->data << endl << endl;
			break;
		}
		ptr = ptr->link;
		conter++;
	}	
	return*this;
}

template<class t>
void linked<t>::merge(linked<t>& other)
{
	length = length + other.getlength();
	node<t>* ptr = head;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
    }
		ptr->link= other.head;	
}

template<class t>
linked<t>& linked<t>::DELETE(int index, t& value)
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

	node<t>* ptr = NULL,*delp=head;
	int conter = 1;
	while (conter<index && delp)
	{
		ptr = delp;
		delp = delp->link;
		conter++;
	}
	if (conter == index)
	{
		value = delp->data;
		if (head == delp)
			head = head->link;
		
		else if (delp == tail)
		{
			tail = ptr;
			ptr->link = NULL;
		}
		else
			ptr->link = delp->link;

		delete delp;
		cout << "the value you have delete =  " << value << endl;
		cout << "the value in the head  =  " << head->data << endl;
		cout << "the value in the tail =  " << tail->data << endl;
		length--;
	}
	return *this;
}
