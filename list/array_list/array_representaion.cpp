#include <iostream>
#include <list>
using namespace std;

template <class T>
class Array
{
public:
	Array(const int arrSize);
	~Array() { delete[] items; };
	void fill();
	void display();
	int getSize() { return size;};
	int getLength() { return length;};
	int search(const T& x) const;
	void Append( T& newItem);
	bool find(int index, T& value)const;
	bool isEmpty() { return length; }
	Array<T>& insert(int index,T& newItem);
	Array<T>& Delete(int index, T& value);
	void enLarge(int NEWSIZE);
	void merge(Array<T>& other);
private:
	int size;
	int length;
	T *items;
};

template <class T>
Array<T>::Array(const int arrSize)
{
	size = arrSize;
	length = 0;
	items = new T[arrSize];
}



template <class T>
void Array<T>::fill()
{
	int numerOfItems;
	cout << "how many items do you want to fill ? " << endl;
	cin >> numerOfItems;
	if (numerOfItems > size)
	{
		cout << "you cannot do this " << endl;
	}
	else
	{  
		for (int i = 0; i < numerOfItems; i++)
		{
			cout << "inter item number "<<i+1 << endl;
			cin >> items[i];
			length++;
		}
	}
}

template <class T>
void Array<T>::display()
{
	cout << "Display the array : " << endl;
	for (int i = 0;i < length;i++)
	{
		cout <<items[i]<<"\t";
	}
	cout << endl;
}

template <class T>
int Array<T>::search(const T& x)const
{
	int index = -1;
	for (int i = 0;i < length;i++)
	{
		if (items[i] == x)
		{
			index = i ;
			break;
		}
	}
	return index;
}

template <class T>
void Array<T>::Append(T& newItem)
{
	if (length < size)
	{
		items[length] = newItem;
		length++;
	}
	else
		cout << "array is full" << endl;
}

template <class T>
bool Array<T>::find(int index, T& value)const
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
Array<T>& Array<T>::insert(int index, T& newItem)
{
	if (index >= 0 && index < size)
	{
	
		for (int i = length;i > index;i--)
		{
			items[i] = items[i - 1];
		}
	
		items[index] = newItem;
		length++;

	}
	return*this;

}

template <class T>
Array<T>& Array<T>::Delete(int index, T& value)
{
	if (find(index, value))
	{
		for (int i =index; i < length; i++)
		{
			items[i] = items[i + 1];
		}
		length--;
		return*this;
	}
}


template <class T>
void Array<T>::enLarge(int NEWSIZE) 
{
	if (NEWSIZE <= length)
	{
		cout << "sorry, the new size is smaller than the length " << endl;
		return;
	}
	else
	{
		size = NEWSIZE;
		T* old = items;
		items = new T[size];
			for (int i = 0;i < length;i++)
			{
				items[i] = old[i];
			}
		delete[] old;
	}
}

template <class T>
void Array<T>::merge(Array<T>& other)
{
	size = size + other.getSize();
	T* old = items;
	items = new T[size];
	int i;
	for (i = 0;i < length;i++)
	{
		items[i] = old[i];
	}
	length = length + other.getLength();
	delete[] old;

	for (int j = 0;j < other.getLength();j++)
	{
		items[i++] = other.items[j];
	}
	

}
