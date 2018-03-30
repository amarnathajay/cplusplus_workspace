/*
Author: Ajay S Amarnath
Program to implement a stack using linked lists
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define LENGTH 5

class StackArray
{
        int top;
public:
        float stack[LENGTH];

        //Use a constructor to initialize the value for the top variable, -1 denotes that the stack is empty
        StackArray() { top = -1; }
        void push(float x);
        int pop();
        bool isEmpty();
        void printStack();
        int topVariable();
};

void StackArray::push(float x)
{
        if((top + 1) >= LENGTH)
        {
		//Check if full
                cout << "The stack is full, Overflow. Number not pushed on to the stack" << endl;
        }

        else
        {
                //Insert logic to push on to stack
        }
}

int StackArray::pop()
{
        if (top < 0)
        {
                cout << "The stack is empty, Underflow. Number not popped off the stack" << endl;
                return 0;
        }
        else
        {
                //Enter logic to pop off stack
                return x;
        }
}

bool StackArray::isEmpty()
{
        //Check if empty logic
}

void StackArray::printStack()
{
        if(top < 0)
        {
                cout << "Stack is Empty" << endl;
        }
        else
        {
                for(int i = 0; i <= top; i++)
                {
                        cout << stack[i] << endl;
                }
                cout << endl;
        }
}


int StackArray::topVariable()
{
        return top;
}


int main()
{
        StackArray s;
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
                        cout << len + 1 << endl;
                        }break;

                        default: { exit(0); }
                        break;
                }
        }
	return 0;
}

