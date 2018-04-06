/*
Author: Ajay S Amarnath
Program to just create a basic tree
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int value;
	struct node* left;
	struct node* right;
};

class Tree
{
public:
	struct node* root;
	Tree()
	{
		root = NULL;
	}
	struct node* insert(struct node* n, int num);
	void printInOrder(struct node* n);
	void printPostOrder(struct node* n);
	int minDepth(struct node* n);
	int maxDepth(struct node* n);
	int size(struct node* n);
	int minValue(struct node* n);
};

struct node* Tree::insert(struct node* n, int num)
{
	struct node* newNode;
	newNode = new (struct node);
	newNode->value = num;
	newNode->left = NULL;
	newNode->right = NULL;


	if(n == NULL)
	{
		n = newNode;
	}
	else 
	{
		if(num <= n->value)
		{
			n->left = insert(n->left, num);
		}
		else
		{
			n->right = insert(n->right, num);
		}
	}
	return n;
}

void Tree::printInOrder(struct node* n)
{
	if(n == NULL)
	{	//cout << "Tree is empty" << endl;
		return;
	}

	printInOrder(n->left);
	cout << n->value << endl;
	printInOrder(n->right);
}
void Tree::printPostOrder(struct node* n)
{
	if(n == NULL)
	{
		return;
	}	

	printPostOrder(n->left);
	printPostOrder(n->right);
	cout << n->value << endl;
}

int Tree::minDepth(struct node* n)
{
	return 0;
}

int Tree::maxDepth(struct node* n)
{
	if(n == NULL)
	{
		return 0;
	}
	
	int lDepth = maxDepth(n->left);
	int rDepth = maxDepth(n->right);

	if(lDepth > rDepth)
	{
		return (lDepth + 1);
	}
	else
	{
		return (rDepth + 1);
	}
}

int Tree::minValue(struct node* n)
{
	if (n == NULL)
	{
		return 0;
	}	
	
	struct node* temp = n;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->value;
}

int Tree::size(struct node* n)
{
	if(n == NULL)
		return 0;
	else
		return (size(n->left) + 1 + size(n->right));
}

int main()
{
	Tree t;
	struct node* r = NULL;
	for(;;)
	{
	cout << "Tree operations\n" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Number of objects in the tree" << endl;
	cout << "3. Print inorder" << endl;
	cout << "4. Print Postorder" << endl;
	cout << "5. Minimum value" << endl;
	cout << "Enter any other number to exit" << endl << endl;
	int choice;
	cin >> choice;
	switch(choice)
	{
		case 1:{
			cout << "Insert Selected\nEnter the number to be inserted" << endl;
			int num;
			cin >> num;
			r = t.insert(r, num);
			cout << endl << endl;
		}break;
		case 2:{
			cout << "Number of objects in the tree = " << t.size(r) << endl << endl;
		}break;
		case 3:{
			cout << "Print inorder" << endl;
			t.printInOrder(r);
			cout << endl << endl;
		}break;
		case 4:{
			cout << "Print Postorder" << endl;
			t.printPostOrder(r);
		}break;
		case 5:{
			cout << "Minimum value = " << t.minValue(r) << endl << endl;
		}break;
		default:{
			exit(0);
		}break;
	}
	}
	return 0;
}
