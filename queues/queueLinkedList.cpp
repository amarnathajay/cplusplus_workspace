/*
Author: Ajay S Amarnath
This is a C++ program to implement a queue using a linked list
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//Create the structure of the node in the queue
struct node
{
	float value;
	node *next;
};

class QueueLL{
	int length;
	struct node *front;
	struct node *rear;
	struct node *p;
	struct node *np;
public:
	QueueLL()
	{
		length = 0;
		front = NULL;
		rear = NULL;
		p = NULL;
		np = NULL;
	}
	void insert(float x);
	float remove();
	void printQueue();
	void lengthOfQueue();	
};

void QueueLL::insert(float x)
{
	np = new node;
	np->value = x;
	np->next = NULL;
	if(front == NULL)
	{
		front = np;
		rear = np;
		rear->next == NULL;
	}
	else
	{
		rear->next = np;
		rear = np;
		rear->next = NULL;
	}
	length++;
}

float QueueLL::remove()
{
	float x;
	if(front == NULL)
	{
		cout << "The queue is empty, cannot remove" << endl;
		return 0;
	}
	else
	{
		p = front;
		x = p->value;
		front = front->next;
		delete(p);
		length--;
		return x;
	}
}

void QueueLL::printQueue()
{
	struct node *temp;
	temp = front;
	if(front == NULL)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Printing the queue" << endl;
	while(temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}

void QueueLL::lengthOfQueue()
{
	cout << "The length of the queue is " << length << endl;
}

int main()
{
        QueueLL q;
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
