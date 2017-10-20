/***************************************
COMP 15 HOMEWORK 3
FAVOUR OKEREKE-MBA (fokere01)
main.cpp
09/30/2017
***************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include "GrocerySim.h"

using namespace std;


//ALL CREDIT TO MARK SHELDON FOR THIS FUNCTION
bool got_int(string s, int *resultp)
{
        return sscanf(s.c_str(), "%d", resultp) == 1;
}

int main(int num_args, char *argv[])
{
	//string filename;
	ifstream file;
	int num_stand_lanes, num_express_lanes, max_express_items;

	//using got_int to get the values from the command line input
	if (got_int(argv[1], &num_stand_lanes)){}
	if (got_int(argv[2], &num_express_lanes)){}
	if (got_int(argv[3], &max_express_items)){}

	//Creating an instance of GrocerySim
	GrocerySim store(num_stand_lanes, num_express_lanes, max_express_items);

	//checking if the optional file name was provided
	if( num_args == 5 ){
		file.open(argv[4]);
		store.run(file);
		file.close();
	}
	else{
		store.run(cin);
	}
	

	return 0;
}