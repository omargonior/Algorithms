#include "linked_stack.cpp"

int main()
{
	int item;
	stack<int> s;
	stack<char> st;
	if (st.balanced_parentheses("{(4+5)+9}"))
		cout << " is balanced \n";
	else 
		cout << " is not balanced \n";

	if (st.balanced_parentheses("{4+5}"))
		cout << " is balanced \n";
	else
		cout << " is not balanced \n";

	for (int i = 0;i < 3;i++)
	{
		cout << "enter the item to push \n";
		cin >> item;
		s.push(item);
		s.display();
	}
	s.pop();
	s.display();

	int i,value;
	cout << "enter index to find value in it " << endl;
	cin >> i;
	s.find(i, value);
	if (s.find(i, value)) { cout << "the value = " << value << endl; }
	else { cout << "not found " << endl; }

	cout << "enter a value to search for " << endl;
	cin >> value;
	//s.search(value);
	if (s.search(value) == -1) { cout << "the value not found " << endl; }
	else { cout << "the value is @ the position " << s.search(value) << endl; }

	return 0;
}