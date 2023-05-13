#include "queue_list.cpp"

int main()
{
	Queue<int> Q(10);
	Queue<int> f(10);
	f.Add(1);
	f.Add(2);
	f.Add(3);
	Q.Add(4);

	int arr[100];
	Q.twoqueus(f, arr);

	
/*	int x, value;
	for (int i = 1; i <= 3;i++)
	{
		cout << "Enter value to Enqueue : \n";
		cin >> value;
		q.enQueue(value);
	}
	q.display();

	cout << "the sum of items in queue = " << q.Sum() << endl;
	q.deQueue(value);
	q.display()*/;

	return 0;