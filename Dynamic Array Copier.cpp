// Garrick Morley
// CPSC 300 Project 1
// This program creates a dynamic array that doubles in size when needed

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
#include <algorithm>
using namespace std;

class NumberList {
	public: 
		//default constructor
		NumberList();	
		
		//destructor
		~NumberList();

		//adds the given number to the array
		void addNumber(int num);
		
		//returns a count of the numbers in the list
		double listSize();
		
		//returns a count of how many times the given number appears in the list
		double numberCount(int num);
		
	private:
		int *numbers = NULL;
		int count;
		int capacity;
		
};

//member function definitions

//constructor
NumberList::NumberList()
{
	count = 0;
	capacity = 5;
	numbers = new int[capacity];
}

//destructor
NumberList::~NumberList()
{
	delete [] numbers;
}

//add a number to the list
void NumberList::addNumber(int num)
{
	
	if(capacity == count)
	{
		capacity *= 2;
		int *ptr = new int[capacity];
		for(int i = 0; i < capacity; i++)
			ptr[i] = numbers[i];
		delete [] numbers;
		numbers = ptr;
	}
	numbers[count] = num;
	count++;
}

//return a count of the numbers in the list
double NumberList::listSize()
{
	return count;
}

//return a count of how many times the given number appears in the list
double NumberList::numberCount(int num)
{
	int instances = 0;
	for(int i = 0; i < count; i++)
	{
		if(numbers[i] == num)
		{
			instances++;
		}	
	}
	return instances;
}

int main()
{
	//declare variables
	int scores;
	int counting;
	
	//initialize the dynamic array
	NumberList list;
	
	//open file
	ifstream input;
	input.open("p1");
	
	//make sure it opened correctly
	if (input.fail())
		cout << "File did not open correctly" << endl;
		
	//input file into dynamic array and print the size
	while(input >> scores)
	{
		list.addNumber(scores);
		cout << "List size: " << list.listSize() << endl;
	}
	
	//Count the given number
	while(1>0)
	{
		cout << "Enter the number you want to count: " << endl;
		cin >> counting;
		cout << "The number " << counting << " appears " << list.numberCount(counting) << " times" << endl;
	}
	return 0;
}















