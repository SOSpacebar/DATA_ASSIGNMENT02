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
		head_ = 0;

	else
		prev->next = 0; //Remove the node.

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
	prev->next = newNode;
}

int LinkedList::pop_at(int pos)
{
	if (!head_)
	{
		return 0;
	}

	Node* curr = head_;
	Node* prev = 0;
	int position = 0;

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
Queue::Queue() : front_(0) , back_(0)
{
}

Queue::~Queue()
{   
	while (front_)
	{
		dequeue();
	}
}

void Queue::enqueue(int data)
{
	Node* newNode = new Node(data);

	if (!front_)
	{
		front_ = newNode;
		back_ = front_; //Put the address togather..
		return;
	}

	back_->next = newNode;
	back_ = newNode;
}

int Queue::dequeue()
{
	if (!front_)
	{
		return 0;
	}

	if (front_ == back_)
	{
		back_ = 0;
	}

	Node* curr = front_;

	front_ = curr->next;

	int returnData = curr->data;

	delete curr;
	return returnData;
}

size_t Queue::size()
{
	if (!front_)
	{
		return 0;
	}

	Node* curr = front_;
	int count = 0;

	while (curr)
	{
		count++;
		curr = curr->next;
	}

	return count;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() : top_(0)
{

}

Stack::~Stack()
{
	while (top_)
	{
		pop();
	}
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);

	Node* prev = 0;

	if (!top_)
	{
		top_ = newNode;
		return;
	}

	prev = top_;
	top_ = newNode;
	top_->next = prev;
}

int Stack::pop()
{
	if (!top_)
	{
		return 0;
	}

	Node* curr = top_;

	top_ = curr->next;

	int returnData = curr->data;

	delete curr;
	return returnData;
}

size_t Stack::size()
{
	if (!top_)
	{
		return 0;
	}

	Node* curr = top_;
	int count = 0;

	while (curr)
	{
		count++;
		curr = curr->next;
	}

	return count;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
	stack <char> left_Stack;
	stack <char> right_Stack;

	for (size_t i = 0; i < input.size(); i++)
	{
		//Check for invaild characters
		if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' || input[i] == '<' || input[i] == '>')
		{
			//Check for left brackets then push into the stack
			if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<')
			{
				//Check if 'i' no over the size. Then check the current input next is the close bracket.
				if (i != input.size() - 1  && (input[i] == input[i + 1] - 1 || input[i] == input[i + 1] - 2))
				{
					i++;
					continue;
				}

				left_Stack.push(input[i]);
			}
		}

		else
		{
			return false;
		}
	}

	for (size_t i = input.size() - 1; i > 0; i--)
	{
		//Check for invaild characters
		if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' || input[i] == '<' || input[i] == '>')
		{
			//Check for right brackets then push into the stack
			if (input[i] == ')' || input[i] == '}' || input[i] == ']' || input[i] == '>')
			{
				//Check if 'i' more then 0. Then check the current input next is the open bracket.
				if (i > 0 && (input[i] - 1 == input[i - 1] || input[i] - 2 == input[i - 1]))
				{
					if (i != 1)
						i--;
					
					continue;
				}
				
				right_Stack.push(input[i]);
			}
		}

		else
		{
			return false;
		}
	}


	if (left_Stack.size() != right_Stack.size())
		return false;


	while (!right_Stack.empty() && !left_Stack.empty())
	{
		if (left_Stack.top() == right_Stack.top() - 1 || left_Stack.top() == right_Stack.top() - 2)
		{
			left_Stack.pop();
			right_Stack.pop();
		}

		else
		{
			return false;
		}
	}

	return true;

	/* Attempted to use queue.
	if (input.size() % 2 != 0)
	{
		return false;
	}

	queue <char> dataQueue;

	for (size_t i = 0; i < input.size(); i++)
	{
		//Check for invaild characters
		if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' || input[i] == '<' || input[i] == '>')
		{
			dataQueue.push(input[i]);

			if (dataQueue.front() == dataQueue.back() - 1 || dataQueue.front() ==  dataQueue.back() - 2)
			{
				char tempF = dataQueue.front();
				char tempB = dataQueue.back();
				dataQueue.pop();
			}

			if (dataQueue.empty() && i < input.size())
			{
				return true;
			}
		}

		else
		{
			return false;
		}
	}

	
	return false;*/
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	map<int, unsigned> count;

	for (size_t i = 0; i < queries.size(); i++)
	{
		count[queries[i]] = 0;
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		if (count.find(data[i]) != count.end())
		{
			count[data[i]]++;
		}
	}

	for (size_t i = 0; i < queries.size(); i++)
	{
		results.push_back(count[queries[i]]);
	}
}