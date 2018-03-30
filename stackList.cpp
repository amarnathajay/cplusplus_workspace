/*
Author: Ajay S Amarnath
Program to implement a stack using linked lists
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define LENGTH 5

//Create the structure for the node in the linked list
struct node
{
	float value;
	struct node *next;
};

class StackList
{
        int top;
	struct node *topNode;
public:
        float stack[LENGTH];

        //Use a constructor to initialize the value for the top variable, -1 denotes that the stack is empty
        StackList() 
	{ 
		top = 0;
		topNode = NULL; 
	}
        void push(float x);
        int pop();
        bool isEmpty();
        void printStack();
        int topVariable();
};

void StackList::push(float x)
{
	float value;
	struct node *p;
	p = new node;
	p->value = x;
	p->next = NULL;
	if(topNode != NULL)
		p->next = topNode;
	topNode = p;
	top = top + 1;
}

int StackList::pop()
{
	struct node *temp;
        if (topNode == NULL)
        {
                cout << "The stack is empty, Underflow. Number not popped off the stack" << endl;
                return 0;
        }
        else
        {
                //Enter logic to pop off stack
		temp = topNode;
		topNode = topNode->next;
		float x;
		x = temp->value;
		delete temp;
		top = top - 1;
                return x;
        }
}

bool StackList::isEmpty()
{
        //Check if empty logic
	if (topNode == NULL)
        {
                cout << "The stack is empty" << endl;
                return true;
        }
	else
		return false;
}

void StackList::printStack()
{
	struct node *p = topNode;
        if(topNode == NULL)
        {
                cout << "Stack is Empty" << endl;
        }
        else
        {
                while(p != NULL)
		{
			cout << p->value << endl;
			p = p->next;
		}
                cout << endl;
        }
}


int StackList::topVariable()
{
        return top;
}


int main()
{
        StackList s;
        for(;;)
        {
                cout << "1. Push" << endl << "2. Pop" << endl << "3. Check if empty" << endl << "4. Print the stack" << endl << "5. Current length of stack" << endl << "0. Exit" << endl << endl;
                int choice;
                cin >> choice;

                switch(choice)
                {
                        case 1: {cout << "Push Selected. Enter the value to push on to the stack" << endl;
                        int num;
                        cin >> num;
                        s.push(num);
                        }
                        break;

                        case 2: {cout << "Pop selected" << endl;
                        cout << s.pop() << " has been popped from the stack" << endl;
                        }break;

                        case 3: {cout << "Check if empty selected" << endl;
                        s.isEmpty() ? cout << "Empty" << endl : cout << "Not Empty" << endl;
                        }break;

                        case 4: {cout << "Print stack selected" << endl;
                        s.printStack();
                        }break;

                        case 5: {cout << "Current length of stack selected" << endl;
                        int len = s.topVariable();
                        cout << len << endl;
                        }break;

                        default: { exit(0); }
                        break;
                }
        }
	return 0;
}

