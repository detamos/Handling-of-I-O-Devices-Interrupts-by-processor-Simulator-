#include <iostream>
#include "priorityQueue.hpp"
#include "../lib/priorityQueue.cpp"

using namespace std;
using namespace cs202;

int main()
{
	LinearList<int> arr;
	int temp,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	MinPriorityQueue<int> queue(arr);
	cout<<"Priority Queue is as follows : \n";
	queue.print();
	cout<<endl;
	while(1)
	{
		cout<<"1.Insert a new number.\n";
		cout<<"2.Get the minimum value.\n";
		cout<<"3.Extract the minimum.\n";
		cout<<"4.Size of the priority queue.\n";
		cout<<"5.Print the priority queue.\n";
		cout<<"\nEnter your choice : ";
		int choice;
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"Enter the key : ";
			cin>>choice;
			queue.insert(choice);
			break;
		case 2:
			choice = queue.minimum();
			if(choice == defValue)
			{
				cout<<"Queue empty.\n";
				break;
			}
			cout<<"Minimum Value : "<<choice<<endl;
			break;
		case 3:
			choice = queue.extract_min();
			if(choice == defValue)
			{
				cout<<"Queue empty.\n";
				break;
			}
			cout<<"Minimum Value : "<<choice<<" deleted.\n";
			break;
		case 4:
			cout<<"Size of the priority queue : "<<queue.heap_size()<<endl;
			break;			
		case 5:
			queue.print();
			break;
		default: return 0;
		}
		cout<<endl;
	}
	return 0;
}