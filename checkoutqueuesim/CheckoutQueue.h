/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
CheckoutQueue.h
09/30/2017
***************************************/
#ifndef CHECKOUTQUEUE_H_
#define CHECKOUTQUEUE_H_

#include "shopper.h"

class CheckoutQueue
{
	public:
		/*constructor*/
		CheckoutQueue();

		/*deconstrcotor*/
		~CheckoutQueue();

		/*
		isEmpty: Checks if a queue is empty and returns a bool 
		No parameter and returns a bool
		*/
		bool isEmpty();

		/*
		size: returns the number of shoppers in the queue
		Parameter: none
		Return Type: int
		*/
		int size();

		/*
		totalItems: returns the number of items_left of every shopper in the
		queue.
		Parameter: none
		Return Type: int
		*/
		int totalItems();

		/*
		enqueue: Adds a shopper to the back of the queue
		Parameter: Shopper
		Return Type: none
		*/
		void enqueue(Shopper shopper);

		/*
		front: returns a reference to the element at the front of the list
		Parameter: none
		Return Type: Shopper.
		*/
		Shopper *front();

		/*
		dequeue: removes a shopper from the front of the queue
		Parameter: none
		Return Type: none
		*/
		void dequeue();

	private:
		struct shopperNode{
			Shopper shopper;
			shopperNode *next;
			shopperNode *prev;
		};

		//size of the list
		int intSize;
		//pointer to the front
		shopperNode *head;
		//pointer to the back
		shopperNode *back;

		/*
		Parameter: none
		Return Type: void
		*/
		void deleteFront();

		/*
		addNewNode: a helper function that creates a new node for a new queue
		Parameter: a char
		Return Type: void
		*/
		void addNewNode(Shopper shopper);
			
		//REMEMBER TO MAKE THIS PRIVATE
		void print();
			
};

#endif