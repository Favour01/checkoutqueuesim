/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
CheckoutQueue.cpp
09/30/2017
***************************************/
#include <iostream>
#include "CheckoutQueue.h"

using namespace std;
/*
Empty Constructor
*/
CheckoutQueue::CheckoutQueue(){
	head = NULL;
	back = NULL;
	intSize = 0;
}

/*
Destructor
Frees all memory allocated on the heap
*/
CheckoutQueue::~CheckoutQueue(){
	while (not isEmpty())
                deleteFront();
}


/*
deleteFront
deletes the node at the front of the list 
*/
void CheckoutQueue::deleteFront(){
	if(intSize == 1){
		shopperNode *tempNode;
		tempNode = head;
		head = NULL;
		back = NULL;
		delete tempNode;
	}
	else{
		shopperNode *tempNode;
        	tempNode = head;
       	 	head = head->next;
       		head->prev = NULL;
        	delete tempNode;
    }
        intSize--;
}

/*
addNewNode
a helper function that creates a new node for a new list
*/
void CheckoutQueue::addNewNode(Shopper shopper)
{
	head = new shopperNode;
	back = head;
	head->next = NULL;
	head->prev = NULL;
	head->shopper = shopper;
}


/*
isEmpty
Checks if a list is empty and returns a bool 
*/
bool CheckoutQueue::isEmpty(){
	if(head == NULL)
		return true;
	else
		return false;  
}

/*
size
returns the size of the list
*/
int CheckoutQueue::size(){
	return intSize;
}

void CheckoutQueue::enqueue(Shopper shopper){
	if(isEmpty())
		addNewNode(shopper);
	else{ 
		shopperNode *tempNode = new shopperNode;
		back->next = tempNode;
		tempNode->prev = back;
		tempNode->shopper = shopper;
		tempNode->next = NULL;
		back = tempNode;
	}
	intSize++;
}

void CheckoutQueue::dequeue(){
	if(isEmpty()){
		throw runtime_error("list_is_empty");
	}
	deleteFront();
}

Shopper *CheckoutQueue::front(){
	if(isEmpty()){
		throw runtime_error("list_is_empty");
	}
	return &head->shopper;
}

int CheckoutQueue::totalItems(){
	int sum = 0;
	shopperNode *tempNode;
	tempNode = head; 
	while(tempNode != NULL){
		sum += tempNode->shopper.items_left;
		tempNode = tempNode->next;
	}
	return sum;
}

void CheckoutQueue::print(){
	shopperNode *tempNode;
	tempNode = head; 
	while(tempNode != NULL){
		cout << "Shopper ID: " << tempNode->shopper.id << endl
			 << "Arrival time: " << tempNode->shopper.arrival_time << endl
			 << "Num Items: " << tempNode->shopper.num_items << endl
			 << "Items Left: " << tempNode->shopper.items_left << endl;
		cout << endl;
		tempNode = tempNode->next;
	}
}
