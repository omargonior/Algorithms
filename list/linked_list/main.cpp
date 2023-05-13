#include "linked_list.cpp"


int main()
{
	linked<int> l1;
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
	l1.display();
	cout << "the length : " << l1.getlength() << endl;


	cout << " we will do merge \n enter a value to insert first in the new list " << endl;
	cin >> value;
	linked<int> l2;
	l2.insertFirst(value);
	cout << "enter a value to insert first " << endl;
	cin >> value;
	l2.insertFirst(value);
	l2.display();
	cout << "after the merge : " << endl;
	l1.merge(l2);
	l1.display();
	cout << "the length after merge : " <<l1.getlength() <<endl;


	cout << "enter a value to insert before the index " << endl;
	cin >> value;
	cout << "enter  the index " << endl;
	cin >> x;
	l1.insertBefore(x, value);
	l1.display();



	cout << "enter a value to insert after the index " << endl;
	cin >> value;
	cout << "enter  the index " << endl;
	cin >> x;
	l1.insertAfter(x, value);
	l1.display();


	cout << "enter index to delete value in it " << endl;
	cin >> x;
	l1.DELETE(x, value);
	l1.display();


	cout << "enter index to find value in it " << endl;
	cin >> x;
	//l1.find(x,value);
	if(l1.find(x, value)) {	cout << "the value = " << value << endl;}
	else { cout << "not found " << endl; }


	cout << "enter a value to Append it " << endl;
	cin >> value;
	l1.Append(value);
	l1.display();


	cout << "enter a value to search for " << endl;
	cin >> value;
	//l1.search(value);
	if (l1.search( value)==-1) { cout << "the value not found "  << endl; }
	else { cout << "the value is at the position " << l1.search(value) << endl; }


	cout << "enter a value to search for " << endl;
	cin >> value;
	l1.search(value);
	if (l1.search(value) == -1) { cout << "the value not found " << endl; }
	else { cout << "the value is at the position " << l1.search(value) << endl; }

	
	return 0;
};