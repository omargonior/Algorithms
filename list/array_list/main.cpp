#include "array_representaion.cpp"

int main()
{
	cout << "hello, enter the array size" << endl;
	int arraySize;
	cin >> arraySize;
	Array<int> arr(arraySize);
	arr.fill();
	arr.display();

	
	cout << "Array size = " << arr.getSize() << endl;
	cout << "Array length = " << arr.getLength() << endl;


	int x, value = 0;
	cout << " enter the index to find the value in it  " << endl;
	cin >> x;
	if (arr.find(x, value))
		cout << "the value in this index is:" << value << endl;
	else
		cout << "not found " << endl;


	cout << " enter the value to insert " << endl;
	cin >> value;
	cout << " enter the index to insert value in it " << endl;
	cin >> x;
	arr.insert(x, value).display();
	//arr.display();
	cout << "Array size = " << arr.getSize() << endl;
	cout << "Array length = " << arr.getLength() << endl;


	cout << "hello, enter the array size to do the merge" << endl;
	cin >> arraySize;
	Array<int> R(arraySize);
	R.fill();
	R.display();
	cout << "now we well do the merge :" << endl;
	arr.merge(R);
	arr.display();
	cout << "Array size after merge = " << arr.getSize() << endl;
	cout << "Array length after merge = " << arr.getLength() << endl;

	cout << " enter the value to search for " << endl;
	cin >> value;
	//arr.search(x);
	if (arr.search(value) != -1)
		cout << "the value you search for ia at the position :" << arr.search(value) << endl;
	else
		cout << "not found " << endl;



	cout << " enter the value to Append" << endl;
	cin >> x;
	arr.Append(x);
	arr.display();
	arr.getLength();
	arr.getSize();

	arr.Delete(2, x);
	cout << "you have delete " << x << endl;
	arr.getLength();
	arr.getSize();
	arr.display();

	return 0;
}
