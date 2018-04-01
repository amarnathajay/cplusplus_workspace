/*
Author: Ajay S Amarnath
Program to delete a specified node
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	float value;
	struct node* next;	
};

class Deleted
{
	struct node* head;
public:
	Deleted()
	{
		head = NULL;
	}
	void insert(float value);
	void printList();
	void deleteNode(float x);
};

void Deleted::insert(float value)
{
	struct node* newNode;
	newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;	
	}
	/*else
	{
		curr = head;
		while(curr->next != NULL && curr->next->value < newNode->value)
		{
			
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}*/
	
}

void Deleted::printList()
{
	struct node* temp = head;
	while(temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

void Deleted::deleteNode(float x)
{
	struct node* temp;
	if(head == NULL)
	{	
		cout << "The list is empty" << endl;
	}
	else if(head->value == x)
	{	
		if(head->next == NULL)
		{
			cout << "Removing the last item in the list" << endl;
		}
		cout << "Removing head" << endl;
		head = head->next;
	}
	else
	{
		temp = head;
		while(temp->next != NULL && temp->next->value != x)
		{
			temp = temp->next;
		} 
		if (temp->next == NULL)
		{
			cout << "The node is not present in the linked list" << endl;
			return; 
		}

		temp->next = temp->next->next;
		
	}
}

int main()
{
	Deleted d;
	for(;;)
        {
	cout << "1. Insert" << endl << "2. Print the stack" << endl << "3. Delete" << endl << "0. Exit" << endl << endl;
                int choice;
                cin >> choice;

                switch(choice)
                {
                        case 1: {cout << "Insert Selected.\n Enter the value to insert on to the sorted list" << endl;
                        float num;
                        cin >> num;
                        d.insert(num);
                        }
                        break;

                        case 2: {cout << "Print List selected" << endl;
                        d.printList();
                        }break;

			case 3: {
			cout << "Delete Selected.\n Enter the value to delete from the sorted list" << endl;
                        float n;
                        cin >> n;
                        d.deleteNode(n);
			}break;

                        default: { exit(0); }
                        break;
                }
        }
	return 0;
}

