#include <iostream>
#include "priorityQueue.hpp"
#include "../lib/priorityQueue.cpp"

using namespace cs202;
using namespace std;

class Device
{
public:	
	int id,burstTime,delay,priority;
	bool operator<(const Device &a)
	{
		return (this->priority < a.priority);
	}
};

int main()
{
	int n;
	cin>>n;
	LinearList<Device> device;
	Device temp;
	int requestTime[n];
	for(int i=0;i<n;i++)
	{
		cin>>temp.id>>temp.burstTime>>temp.delay>>temp.priority;
		device.push_back(temp);
		requestTime[i] = temp.delay;
		if(i)
			requestTime[i] += requestTime[i-1];
	}
	int index = 1,time = 0;
	MinPriorityQueue<Device> q;
	int cpuPriority = device[0].priority;
	Device current = device[0];
	while(index < n)
	{
		if(current.burstTime != 0)
			cpuPriority = current.priority;
		else
			cpuPriority = 10;
		if(time == requestTime[index])
		{
			cout<<"Interruption by : "<<device[index].id<<endl;
			cout<<"CPU Priority : "<<cpuPriority<<"\n";
			cout<<"New Priority : "<<device[index].priority<<endl;
			if(cpuPriority > device[index].priority)
			{	
				if(current.burstTime != 0)
					q.insert(current);
				current = device[index];
				cpuPriority = current.priority;
				cout<<"New task Started\n";
			}
			else
			{
				cout<<"Continuing old task\n";
				q.insert(device[index]);
			}
			index++;
		}
		if(current.burstTime == 0)
		{
			if(!q.empty())
			{
				current = q.extract_min();
				cpuPriority = current.priority;
			}
			else
			{
				current.burstTime = 0;
				cpuPriority = 10;
				time++;
				cout<<"Time : "<<time<<"\tExecuting : Garbage\n";
				continue;
			}
		}
		current.burstTime--;
		time ++;
		cout<<"Time : "<<time<<"\t"<<"Executing : "<<current.id<<endl;
	}
	while(current.burstTime)
	{
		current.burstTime--;
		time++;
		cout<<"Time : "<<time<<"\t"<<"Executing : "<<current.id<<endl;
	}
	while(!q.empty() || current.burstTime != 0)
	{
		if(current.burstTime == 0)
		{
			current = q.extract_min();
			cout<<"New Task Started\n"<<current.id<<endl;
		}
		current.burstTime--;
		time++;
		cout<<"Time : "<<time<<"\t"<<"Executing : "<<current.id<<endl;
	}
	cout<<"END\n";
	return 0;
}