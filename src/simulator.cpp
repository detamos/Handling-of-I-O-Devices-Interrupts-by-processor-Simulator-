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
	for(int i=0;i<n;i++)
	{
		cin>>temp.id>>temp.burstTime>>temp.delay>>temp.priority;
		device.push_back(temp);
	}
	MinPriorityQueue<Device> queue;
	int time = 0;
	queue.insert(device[0]);
	int cpuPriority = 10;
	int index = 1;
	while(!queue.empty())
	{
		Device temp = queue.extract_min();
		cpuPriority = temp.priority;
		if(temp.burstTime <= device[index].burstTime)
		{
			cpuPriority = 10;
			queue.push_back(device[index]);
			index++;
			continue;
		}
		else
		{
			break;
		}
	}
	return 0;
}