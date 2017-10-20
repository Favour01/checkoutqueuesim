/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
testCheckoutQueue.cpp
09/30/2017
***************************************/
#include <iostream>
using namespace std;
#include "CheckoutQueue.h"
//#include "shopper.h"

void testcons();
void testfront();
void testdequeue();

int main()
{
	cout << "**********TESTING CONSTRCUTOR & ENQUEUE**********" << endl;
	testcons();

	cout << "**********TESTING FRONT**********" << endl;
	testfront();

	cout << "**********TESTING DEQUEUE**********" << endl;
	testdequeue();
}

void testcons(){
	CheckoutQueue queue;
	int check = 0;
	for (int i = 0; i < 3; i++){	
		Shopper shopper;
		shopper.id = i + 1;
		shopper.arrival_time = i;
		shopper.num_items = i;
		shopper.items_left = i;
		queue.enqueue(shopper);
		check += i;
	}
	queue.print();

	cout << "**********TESTING TOTALITEMS**********" << endl;
	int ans = queue.totalItems();
	cout << "The expected total is : " << check << endl;
	cout << "The total number of items in the queue: " << ans << endl << endl;
}

void testfront(){
	CheckoutQueue queue;
	for (int i = 0; i < 2; i++){	
		Shopper shopper;
		shopper.id = i + 1;
		shopper.arrival_time = i;
		shopper.num_items = i;
		shopper.items_left = i;
		queue.enqueue(shopper);
	}
	queue.print();
	cout << "After calling : " << endl << endl;
	Shopper *first = queue.front();
	first->id = 10;
	first->arrival_time = 15;
	first->items_left = first->items_left + 20;
	queue.print();
	
}

void testdequeue(){
	CheckoutQueue queue;
	for (int i = 0; i < 2; i++){	
		Shopper shopper;
		shopper.id = i + 1;
		shopper.arrival_time = i;
		shopper.num_items = i;
		shopper.items_left = i;
		queue.enqueue(shopper);
	}
	queue.print();
	cout << "After calling deque: " << endl << endl;
	queue.dequeue();
	queue.print();
}