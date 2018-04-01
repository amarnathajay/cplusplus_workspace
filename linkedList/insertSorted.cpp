/*
Author: Ajay S Amarnath
Program to implement a linked list which is sorted where insertion is done and it maintains the sort
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	float value;
	struct node* next;	
};

class Sorted
{
	struct node* head;
public:
	Sorted()
	{
		head = NULL;
	}
	void insertSorted(float value);
	void printList();
};

void Sorted::insertSorted(float value)
{
	struct node* newNode;
	struct node* curr;
	newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
	}
	else if(head->value > newNode->value)
	{
		newNode->next = head;
		head = newNode;	
	}
	else
	{
		curr = head;
		while(curr->next != NULL && curr->next->value < newNode->value)
		{
			
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	
}

void Sorted::printList()
{
	struct node* temp = head;
	while(temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

int main()
{
	Sorted s;
	for(;;)
        {
                cout << "1. Insert" << endl << "2. Print the stack" << endl << "0. Exit" << endl << endl;
                int choice;
                cin >> choice;

                switch(choice)
                {
                        case 1: {cout << "Insert Selected.\n Enter the value to insert on to the sorted list" << endl;
                        float num;
                        cin >> num;
                        s.insertSorted(num);
                        }
                        break;

                        case 2: {cout << "Print List selected" << endl;
                        s.printList();
                        }break;

                        default: { exit(0); }
                        break;
                }
        }
	return 0;
}
