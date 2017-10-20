/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
GrocerySim.cpp
09/30/2017
***************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "GrocerySim.h"

using namespace std;

/*********************
comstructor
initialises required array(s) of queues and needed variables
*********************/
GrocerySim::GrocerySim(int num_stand1, int num_express1, int max_items){
	stand_queue = new CheckoutQueue[num_stand1];
	express_queue = new CheckoutQueue[num_express1];
	max_express = max_items;
	arrival_time = NULL;
	num_items = NULL;
	//number of shoppers in the file.
	num_stand = num_stand1;
	num_express = num_express1;
	num_shoppers = 0;
	index = 0;
	time = 0;
}

/**************************
Destructor
*****************************/
GrocerySim::~GrocerySim(){
	delete[] stand_queue;
	delete[] express_queue;
	delete[] arrival_time;
	delete[] num_items;
}

/**************************
run
The run function calls the read_from_file function
and the simulate funtion which simulates a tore.
Called by main()
*****************************/
void GrocerySim::run(istream &filename){
	read_from_file(filename);
	simulate();	
}

/**************************
shortest_queue
return a char to that determines if the shortest queue is a 
standard queue or express queue and updates the queue index in the
array by reference. Called by Distribute().
*****************************/
char GrocerySim::shortest_queue(int &spot, int check){	
	int sum = (10 * 10) ^ 500, sum1 = (10 * 10) ^ 500;
	int temp, temp1, pos = 0, pos1 = 0;
	for (int i = 0; i < num_stand; i++){
		temp = stand_queue[i].totalItems();
		if (temp == 0){
			pos = i; break;
		}
		else{
			if (temp <= sum){
				pos = i; sum = temp;
			}
		}
	}
	for (int i = 0; i < num_express; i++){
		temp1 = express_queue[i].totalItems();
		if (temp1 == 0){
			pos1 = i; break;
		}
		else{
			if (temp1 <= sum1){
				pos1 = i; sum1 = temp1;
			}
		}
	}
	if ((temp1 <= temp) && (num_items[check] <= max_express)){
		spot = pos1; return 'e';
	}
	else{
		spot = pos; return 's';
	}
}

/**************************
new_shopper
returns an instance of the shopper struct after updating the
required fields. Called by distribute().
*****************************/
Shopper GrocerySim::new_shopper(int i){
	Shopper shopper;
	shopper.id = i + 1;
	shopper.arrival_time = arrival_time[i];
	shopper.num_items = num_items[i];
	shopper.items_left = shopper.num_items;
	return shopper;
}

/**************************
read_from_file
reads in the shopper arrival time and number of items
variables and then calls creatboard() to place them in variables
as they are read in.
*****************************/
void GrocerySim::read_from_file(istream &filename){
	int temp1, temp2, count = num_shoppers;
	while (filename >> temp1 >> temp2){
		num_shoppers++;
		create_board(temp1, temp2);
	}
	if(count == num_shoppers)
		exit(0);
}

/**************************
create_board
called by read_from file. Used to create two dynamic arrays.
One is used to hold the arrival_time of the shopppers and the
other is used to hold num_items. Calls expand.
*****************************/
void GrocerySim::create_board(int temp1, int temp2){
	if(arrival_time == NULL){
		arrival_time = new int[num_shoppers];
		num_items = new int[num_shoppers];
		arrival_time[0] = temp1; 
		num_items[0] = temp2;
	}
	else
		expand(temp1, temp2);
}

/**************************
ptinr_array
print function used to test if information was read in
from file properly by printing the two arrays that contain
the information to screen.
*****************************/ 
void GrocerySim::print_array(){
	for (int i = 0; i < num_shoppers; i++)
    {
        cout << arrival_time[i] << "\t";
        cout << num_items[i] << "\t";
        cout << endl;
    }
	return;
}

/**************************
expand
expands arrays so as to contain more shopper info as they
aare read in from file
*****************************/
void GrocerySim::expand(int temp1, int temp2){
	int *tempa = new int[num_shoppers];
	int *tempi = new int[num_shoppers];
	for(int i = 0; i < num_shoppers - 1; i++){
		tempa[i] = arrival_time[i];
		tempi[i] = num_items[i];
	}
	tempa[num_shoppers - 1] = temp1;
	tempi[num_shoppers - 1] = temp2;
	delete[] arrival_time;
	delete[] num_items;
	arrival_time = tempa;
	num_items = tempi;  
}

/**************************
distribute
distibutes a new shopper to the appropriate queue when
they are ready to check out. Calls new_shopper, 
shortest_queue and enqueue.
*****************************/
void GrocerySim::distribute(){
	int spot = 0, count = 0;
	for (int i = index; i < num_shoppers; i++){
		if (count == (num_stand + num_express)){
			break;
		}
		if (arrival_time[i] != time){
			break;
		}
		else{
			Shopper shopper;
			shopper = new_shopper(i);
			char which_queue = shortest_queue(spot, i);
			if (which_queue == 'e')
				express_queue[spot].enqueue(shopper);
			if (which_queue == 's')
				stand_queue[spot].enqueue(shopper);
			index = i + 1;
		}
		count++;
	}
}


/**************************
empty_store
sums all the items in every queue and returns true
if the sum == 0 and false otherwise. Used to check
if the store is empty.
*****************************/
bool GrocerySim::empty_store(){
	int sum = 0;
	for (int i = 0; i < num_stand; i++)
		sum += stand_queue[i].totalItems();
	for (int i = 0; i < num_express; i++)
		sum += express_queue[i].totalItems();
	if (sum == 0)
		return true;
	else
		return false;
}

/**************************
process
Kicks off the process of processing shoppers by
calling process_express and process_stand.
*****************************/
void GrocerySim::process(){
	process_stand();
	process_express();
}

/**************************
process_express
Reduces the items_left for every shooper at the
front of an express queue and dequeues the shopper if
the items_left reaches zero. Calls print.
*****************************/
void GrocerySim::process_express(){
	for (int i = 0; i < num_express; i++){
		if (!express_queue[i].isEmpty()){
			Shopper *first = express_queue[i].front();
			first->items_left = first->items_left - 1;
			if (first->items_left == 0){
				print('e', i);
				express_queue[i].dequeue();
			}
		}	
	}
}


/**************************
process_stand
Reduces the items_left for every shooper at the
front of an standard queue and dequeues the shopper if
the items_left reaches zero. Calls print.
*****************************/
void GrocerySim::process_stand(){
	for (int i = 0; i < num_stand; i++){
		if (!stand_queue[i].isEmpty()){
			Shopper *first = stand_queue[i].front();
			first->items_left = first->items_left - 1;
			if (first->items_left == 0){
				print('s', i);
				stand_queue[i].dequeue();
			}
		}
	}
}

/***************************
print
prints a shopper that has been completely 
processed to the screen.
******************************/
void GrocerySim::print(char d_queue, int i){
	if (d_queue == 's'){
		Shopper *first = stand_queue[i].front();
		cout << "Shopper " << first->id << " arrived at " << 
		first->arrival_time << " with " << first->num_items 
		<< " items, took " << time - first->arrival_time << " units\n";
	}
	if (d_queue == 'e'){
		Shopper *first = express_queue[i].front();
		cout << "Shopper " << first->id << " arrived at " << 
		first->arrival_time << " with " << first->num_items 
		<< " items, took " << time - first->arrival_time << " units\n";
	}
}



/***************************
simulate
Takes care of the whole simulation by calling the two
core functions, process and distribute
******************************/
void GrocerySim::simulate(){
	while(!empty_store() || (index != num_shoppers)){
		process();
		distribute();
		time++;
	}
}