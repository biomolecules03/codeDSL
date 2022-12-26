//Ankit Gyandev More
//Se comp B 
//Roll no.9
#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int rear, front;
	int size;
	int *arr;
public:
	Queue(int s)
	{
		front = rear = -1;
		size = s;
		arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};

void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) 
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	cout<<"The deleted entry is "<<data;
}

void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

int main()
{
    int size;
    cout<<"Enter the size of the queue : ";
    cin>>size;
	Queue q(size);
    int ch;
    do
    {
        cout << "\n\n----------------------MENU--------------------\n\n";
        cout << "1. Enqueue \n2. Dequeue \n3. Exit";
        cout<<"\nEnter your choice : ";
        cin >> ch;

	if(ch==1){
        int val;
        cout<<"Enter the entry to be added: ";
        cin>>val;
        q.enQueue(val);
        q.displayQueue();
    }
    else if(ch==2){
        q.deQueue();
        q.displayQueue();
    }
    } while (ch!=3);
    
    
	
	return 0;
}