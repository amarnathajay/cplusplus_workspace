/*
Author: AJay S Amarnath
A program that uses linked lists in order to simulate the function of strcmp()
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//Structure to hold a single character in a node of the linked list
struct node
{
	char letter;
	struct node* next;
};

class Cmp
{
public:
	struct node* head1;
	struct node* head2;
	Cmp()
	{
		head1 = NULL;
		head2 = NULL;
	}
	node* newNode(char l);
	int compare(node* list1, node* list2);
};

node* Cmp::newNode(char l)
{
	node* temp = new node;
	temp->letter = l;
	temp->next = NULL;
	return temp;
}

int Cmp::compare(node* list1, node* list2)
{
	while(list1 != NULL && list2 != NULL && list1->letter == list2->letter)
	{
		cout << endl << list1->letter << endl << list2->letter << endl;
		list1 = list1->next;
		list2 = list2->next;
	}
	cout << endl << list1->letter << endl << list2->letter << endl;
	if(list1 != NULL && list2 != NULL)
		return (list1->letter > list2->letter) ? 1 : -1;
	cout << endl << list1->letter << endl << list2->letter << endl;
	if(list1 != NULL && list2 == NULL)
		return 1;
	if(list1 == NULL && list2 != NULL)
		return -1;
	else
		return 0;
	
}



int main()
{
	Cmp c;
	
	c.head1 = c.newNode('g');
	c.head1->next = c.newNode('e');
	c.head1->next->next = c.newNode('e');
	c.head1->next->next->next = c.newNode('k');
	c.head1->next->next->next->next = c.newNode('s');
	c.head1->next->next->next->next->next = c.newNode('a');
	//c.head1->next->next->next->next->next->next = c.newNode('a');
	
	c.head2 = c.newNode('g');
	c.head2->next = c.newNode('e');
	c.head2->next->next = c.newNode('e');
	c.head2->next->next->next = c.newNode('k');
	c.head2->next->next->next->next = c.newNode('s');
	c.head2->next->next->next->next->next = c.newNode('b');
	//c.head2->next->next->next->next->next->next = c.newNode('b');

	cout << "Comparing the 2 strings"<< endl << c.compare(c.head1, c.head2);
	return 0;
}
