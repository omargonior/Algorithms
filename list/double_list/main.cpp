#include "double_linked.cpp"

int main()
{
	doublyLinked<int> l1;
	int value, x;
	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);

	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);
	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);
	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);
	
	cout << "enter index to delete  value in it ! " << endl;
	cin >> x;
	l1.DELETE(x, value);
	l1.display();

	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);
	cout << "enter a value to insert first " << endl;
	cin >> value;
	l1.insertFirst(value);
	l1.display();

	l1.median();
	if (l1.min_second() == 0)
		cout << "emty list !\n";
	else if(l1.min_second() == -1)
		cout << "this list has one elment only !\n";
	else
	    cout << "the second mini = " << l1.min_second() << endl;

	cout << "the length of this list : " << l1.getlength() << endl;




	if(l1.sorted())
		cout << "the list is sorted ! " << endl;
	else
		cout << "the list is not sorted ! " << endl;


	cout << "enter a value to insert after " << endl;
	cin >> value;
	cout << "enter an index " << endl;
	cin >> x;
	l1.insertAfter(x,value);
	l1.display();
	cout << "the length of this list : " << l1.getlength() << endl;


	cout << "enter a value to insert after " << endl;
	cin >> value;
	cout << "enter an index " << endl;
	cin >> x;
	l1.insertAfter(x, value);
	l1.display();
	cout << "the length of this list : " << l1.getlength() << endl;
	return 0;
}