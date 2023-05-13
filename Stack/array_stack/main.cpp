#include "stack_array.cpp"

int main()
{
	int value, index,size;

	cout << "ehello, wellcome to stack with array represenation : \n";
	cout << "enter the size of stack : ";
	cin >> size;
    stack<int> s(size);

	cout << "enter the value to push : ";
		cin>> value;
	s.push(value);
	s.display();

	cout << "enter the value to push : ";
	cin >> value;
	s.push(value);
	s.display();

	cout << "enter the value to push : ";
	cin >> value;
	s.push(value);
	s.display();


	cout << "enter the size of stack : ";
	cin >> size;
	stack<int> s2(size);

	cout << "enter the value to push : ";
	cin >> value;
	s2.push(value);
	s2.display();

	cout << "enter the value to push : ";
	cin >> value;
	s2.push(value);
	s2.display();

	cout << "now we will do merge : \n";
	s.merge(s2);
	s.display();
	s.getSize();


	s.pop();
	s.display();

	cout << "enter the index to find the value in it : ";
		cin >> index;
		s.find(index, value);
		if (s.find(index, value)) { cout << "the value = " << value << endl; }
		else { cout << "not found " << endl; }

		cout << "enter a value to search for " << endl;
		cin >> value;
		//s.search(value);
		if (s.search(value) == -1) { cout << "the value not found " << endl; }
		else { cout << "the value is @ the position " << s.search(value) << endl; }


		cout << "enter the size of stack : ";
		cin >> size;
		stack<int> s1(size);

		cout << "enter the value to push : ";
		cin >> value;
		s1.push(value);
		s1.display();

		cout << "enter the value to push : ";
		cin >> value;
		s1.push(value);

		cout << "enter the value to push : ";
		cin >> value;
		s1.push(value);
		s1.display();

		cout << "we will merge : \n ";
		s.merge(s1);


	return 0;
}
