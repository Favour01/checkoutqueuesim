/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
GrocerySim.h
09/30/2017
***************************************/
#ifndef GROCERYSIM_H_
#define GROCERYSIM_H_

#include <fstream>
using namespace std;
#include "CheckoutQueue.h"

class GrocerySim
{
	public:
		/***************************
		Function: Constructor
		Parameters: num_stand1(number of standard arrays)
					num_express1(number of express arrays)
					max_items(maximum number of items to have on an express
					queue)
		Returns: nothing.
		******************************/
		GrocerySim(int num_stand1, int num_express1, int max_items);

		/*deconstructor*/
		~GrocerySim();

		/***************************
		Function: run
		Parameters: file to read from
		Returns: nothing
		******************************/
		void run(istream &filename);

	private:
		//array of standard queues
		CheckoutQueue *stand_queue;

		//array of express queues
		CheckoutQueue *express_queue;

		//the number of standard queues available
		int num_stand;

		//the number of express queues available
		int num_express;

		//maximum number of items to have on an express queue
		int max_express;

		//keeps track of time during simulation 
		int time;

		//array that contains the arrival times of the shoppers 
		int *arrival_time;

		//array that contains the number of items a shopper arrived with
		int *num_items;

		//the total number of shoppers 
		int num_shoppers;

		//keeps track of the current shopper
		int index;

		/***************************
		Function: shortest_queue
		Parameters: &spot (represents the index of the shortest queue 
						   in the array of queues)
					check (the index of the shopper in the array of num_items)
		Returns: a char, 'e' or 's', that represtnts the array of queues to 
				 update. Also updates spot by reference to indicate the postion
				 of the shortest queue in the array of queues.
		******************************/
		char shortest_queue(int &spot, int check);

		/***************************
		Function: new_shopper
		Parameters: i (shoppers id)
		Returns: The newly created shopper
		******************************/
		Shopper new_shopper(int i);

		/***************************
		Function: create_board
		Parameters: temp1(arrival_time of a shopper read from file)
					temp2(num_items of a shopper read from file)
		Returns: nothing
		******************************/
		void create_board(int temp1, int temp2);

		/***************************
		Function: read_from_file
		Parameters: file to read from
		Returns: none
		******************************/
		void read_from_file(istream &filename);

		/***************************
		Function: print_array
		Parameters: none
		Returns: nthing
		******************************/
		void print_array();

		/***************************
		Function: expand
		Parameters: temp1(arrival_time of a shopper read from file)
					temp2(num_items of a shopper read from file)
		Returns: nothing
		******************************/
		void expand(int temp1, int temp2);

		/***************************
		Function: distribute
		Parameters: none
		Returns: nothing
		******************************/
		void distribute();

		/***************************
		Function: empty_store
		Parameters: none
		Returns: A boolean
		******************************/
		bool empty_store();

		/***************************
		Function: process
		Parameters: none
		Returns: nothing
		******************************/
		void process();

		/***************************
		Function: process_stnad
		Parameters: none
		Returns: nothing
		******************************/
		void process_stand();

		/***************************
		Function: process_express
		Parameters: none
		Returns: nothing
		******************************/
		void process_express();

		/***************************
		Function: print
		Parameters: d_queue(what queue to print from)
					i(the position in th queue to print fron)
		Returns: nothing
		******************************/
		void print(char d_queue, int i);

		/***************************
		Function: simulate
		Parameters: none
		Returns: nothing
		******************************/
		void simulate();
};

#endif