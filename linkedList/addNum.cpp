/*Author: Ajay S Amarnath
Program to add 2 numbers represented by liked lists
*/

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
	
struct node
{
	int num;
	struct node* next;
};

class AddNums
{
public:
	node* head1;
	node* head2;

	AddNums()
	{
		head1 = NULL;
		head2 = NULL;
	}
	void insertAtHead1(int num1);
	void insertAtHead2(int num2);
	int add(node* list1, node* list2);
	void printList(node* list);
	//int getSize(node* list);
};

int getSize(node* list)
{
	int size = 0;
	while(list != NULL)
	{
		list = list->next;
		size++;
	}
	return size;
}

void AddNums::insertAtHead1(int num1)
{
	node* temp = new node;
	node* curr = head1;
	temp->num = num1;
	temp->next = NULL;

	if(head1 == NULL)
	{	
		head1 = temp;
	}
	else if(head1->next == NULL)
	{
		head1->next = temp;
	}
	else
	{
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}

}

void AddNums::insertAtHead2(int num2)
{
        node* temp = new node;
	node* curr = head2;
        temp->num = num2;
        temp->next = NULL;

        if(head2 == NULL)
        {
                head2 = temp;
        }
        else if(head1->next == NULL)
        {
                head2->next = temp;
                
        }
	else
        {
                while(curr->next != NULL)
                {
                        curr = curr->next;
                }
                curr->next = temp;
        }
}

int AddNums::add(node* list1, node* list2)
{
	int result = 0;
	if(list1 == NULL)
	{

	}

	if(list2 == NULL)
	{

	}

	int size1 = getSize(list1);
	int size2 = getSize(list2);

	int carry = 0;

	if(size1 == size2)
	{
		for(int i = 0; i < size1; i++)
		{
			result += (list1->num + list2->num) * pow(10,i);
			list1 = list1->next;
			list2 = list2->next;	
		}
		return result;
	}
	return result;
}

void AddNums::printList(node* list)
{
	node* temp;
	temp = list;
	while (temp != NULL)
	{
		cout << temp->num << endl;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	AddNums a;
	int n1 = 232;
	int n2 = 546;
	
	for(int i = n1; i > 0; i =  i / 10)
	{
		a.insertAtHead1(i % 10);
	}
	for(int j = n2; j > 0; j = j / 10)
	{
		a.insertAtHead2(j % 10);
	} 

	a.printList(a.head1);
	a.printList(a.head2);

	int sum;
	sum = a.add(a.head1, a.head2);
	cout << endl << "Sum = " << sum << endl;
	return 0;
}
