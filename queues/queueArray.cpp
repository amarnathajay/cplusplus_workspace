/*
Author: Ajay S Amarnath
A program to implement a queue using arrays */

#include <iostream>
#include <stdlib.h>

using namespace std;

#define LENGTH 5

class QueueArray
{
	int front;
	int rear;
	float queue[LENGTH];

public:
	QueueArray()
	{
		front = 0;
		rear = -1;
		
	}
	void insert(float x);
	float remove();
	void printQueue();
	void lengthOfQueue();
};

void QueueArray::insert(float x)
{
	if(rear == LENGTH - 1)
	{
		cout << "The queue is full" << endl;
		return;
	}
	else
	{
		cout << "Adding " << x << " to the back of the queue" << endl;
		rear++;
		queue[rear] = x;
	}
}

float QueueArray::remove()
{
	if(rear < front)
	{
		cout << "The queue is empty, cannot remove" << endl;
		return 0;
	}
	else
	{	int x;
		x = queue[front];
		for(int i = 0; i <= rear; i++)
		{
			queue[i] = queue[i + 1];
		}
		rear--;
		return x;
	}
}

void QueueArray::printQueue()
{
	if(rear < front)
	{
		cout << "Queue is empty, no items to print" << endl;
	}
	else
	{
		for(int i = front; i <= rear; i++)
		{
			cout << queue[i] << endl;
		}
	}
}

void QueueArray::lengthOfQueue()
{
	if(rear < front)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Length of the queue is " << rear + 1 << endl; 
	}
}

int main()
{
	QueueArray q;
        for(;;)
        {
                cout << "1. Insert" << endl << "2. Remove" << endl << "3. Print the stack" << endl << "4. Current length of queue" << endl << "0. Exit" << endl << endl;
                int choice;
                cin >> choice;

                switch(choice)
                {
                        case 1: {cout << "Insert Selected.\n Enter the value to insert on to the queue" << endl;
                        int num;
                        cin >> num;
                        q.insert(num);
                        }
                        break;

                        case 2: {cout << "Remove selected" << endl;
                        cout << q.remove() << " has been removed from the queue" << endl;
                        }break;

                        case 3: {cout << "Print queue selected" << endl;
                        q.printQueue();
                        }break;

                        case 4: {cout << "Current length of queue selected" << endl;
                        q.lengthOfQueue();
                        }break;

                        default: { exit(0); }
                        break;
                }
        }
	return 0;
}
