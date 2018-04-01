/*
Author: Ajay S Amarnath
This is a program to implement a singly linked list
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//A singly linked list node contains a value and the address to the next variable

struct node
{
	float value;
	struct node *next;
}*start;

//Declare the linked list class

class LinkedList
{
public:
	node* create_node(float value);
	void insert_start();
	void insert_end();
	void insert_at();
	void delete_at();
	
	LinkedList()
	{
		start = NULL;
	}
}

node *LinkedList::create_node(float value)
{
	struct node *temp, *s;
	temp = new(struct node);
	if(temp == NULL)
	{
		cout << "Memory not allocated" << endl;
		return 0;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}

void LinkedList::insert_start()
{
	int value;

	cout << "Enter the value to be inserted into the beginning of the list" << endl;
	cin >> value;
	struct node *temp, *p;
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;
	}

	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
	cout << "The value has been inserted in the beginning" << endl;
}

void LinkedList::insert_end()
{
	int value;

	cout << "Enter the value to be inserted in the end" << endl;
	cin >> value;
	struct node *temp, *s;
	temp = create_node(value);
	s = start;
	while (s->next != NULL)
	{
		s = s->next;
	}
	temp->next = NULL;
	s->next = temp;
	cout << "The value has been inserted in the end" << endl;
}

void LinkedList::delete_at()
{
	int pos, i, counter = 0;
	if(start == NULL)
	{
		cout << "List Empty" << endl;
		return;
	}

	cout << "Enter the position of the value to be deleted" << endl;
	cin >> pos;
	struct node *s, *ptr;
	s = start;
	if(pos ==1);
	{
		start = s->next;
	}

	else
	{
		while(s!=NULL)
		{
			s = s->next;
			counter++;
		}
		if(pos > 0 && pos <= counter)
		{
			s = start;
			for(i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}
			ptr->next = s->next;
		}
		else
		{
			cout << "Position out of range" << endl;
		}
		free(s);
		cout << "Value Deleted" << endl;

	
	}
}

int main()
{
	return 0;
}

