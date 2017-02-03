#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <Ng Jing Jie>
 *  \date      3/2/2017 
 *  \note      <164108J>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head_(0)
{

}

LinkedList::~LinkedList()
{
	while (head_)
		pop_back();
}

void LinkedList::push_front(int data)
{
	Node* newNode = new Node(data);

	if (!head_)
	{
		head_ = newNode;
		return;
	}

	newNode->next = head_;
	head_ = newNode;
}

void LinkedList::push_back(int data)
{
	Node* newNode = new Node(data);

	if (!head_)
	{
		head_ = newNode;
		return;
	}

	Node *curr = head_;

	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = newNode;
}

int LinkedList::pop_front()
{
	if (!head_)
	{
		return 0;
	}

	Node* curr = head_;

	head_ = curr->next;

	int returnData = curr->data;
	
	delete curr;
	return returnData;
}

int LinkedList::pop_back()
{    
	if (!head_) //Check is there a node.
	{
		return 0;
	}

	Node* curr = head_;
	Node* prev = 0;

	while (curr->next) //Advance the node.
	{
		prev = curr;
		curr = curr->next;
	}

	if (!prev)	//Checks if pop to the first node and there is no more prev.
		return 0;
	
	prev->next = 0; //Assign the new node.

	int returnData = curr->data;

	delete curr;
	return returnData;
}

void LinkedList::insert_at(int pos, int data)
{
	Node* newNode = new Node(data);

	if (!head_ || pos <= 0)
	{
		newNode->next = head_;
		head_ = newNode;
		return;
	}

	Node* curr = head_;
	Node* prev = 0;
	int position = 0;

	while (curr && position != pos)
	{
		prev = curr;
		curr = curr->next;
		position++; 
	}

	newNode->next = curr;
	curr = newNode;
}

int LinkedList::pop_at(int pos)
{
	Node* curr = head_;
	Node* prev = 0;
	int position = 0;

	if (!head_)
	{
		return 0;
	}

	if (pos <= 0)
	{
		int returnData = curr->data;
		head_ = curr->next;

		delete curr;
		return returnData;
	}

	while (curr->next && position != pos)
	{
		prev = curr;
		curr = curr->next;
		position++;
	}

	if (position != pos)
		return 0;

	prev->next = curr->next;

	int returnData = curr->data;

	delete curr;
	return returnData;
}

size_t LinkedList::size()
{
	if (!head_)
	{
		return 0;
	}

	Node* curr = head_;
	int count = 0;

	while (curr)
	{
		count++;
		curr = curr->next;
	}

    return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}