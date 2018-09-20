//Author: Ajay S Amarnath
//This is a program to demonstrate different search algorithms from inefficient to efficient
#include <iostream>
#include <array>

using namespace std;

class Search
{
	public:
		//All the public variables and methods here
		int LinearSearch(int arr[], int n, int numElems);
		Search()
		{
			//array = {23, 21, 4, 32, 44, 31};
			//sortedArray = {10, 34, 50, 54, 78, 959};
		}
	private:
		//All the private variables here
		int array[]; 
		int sortedArray[];
};

int Search::LinearSearch(int arr[], int n, int numElems)
{
	//return location where n is present 
	for(int i = 0; i < numElems; i++)
	{
		if(arr[i] == n)
			return i;
	}
	return -1;
}

int main()
{
	Search a;
	int arr[] = {23, 543, 21, 13, 12};
	cout << "Array" << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl << endl;
	int pos = a.LinearSearch(arr, 543, 5);
	cout << "Linear Search - The number is found at position " << pos << endl;
	return 0;
}
