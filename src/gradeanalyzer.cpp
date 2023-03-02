/*
 * The entry point for the grade analyzer
 *
 *  Created on: Feb 17, 2023
 *      Author: adecesa1
 */

#include <iostream>
using namespace std;

#include "ConsoleInputController.h"
using namespace controller;

/**
 * The main method for the grade analyzer
 *
 * Precondition: None
 * Postcondition: None
 *
 * Param: argc the number of arguments
 * Param: argv the arguments
 *
 * Return: 0 to indicate the program is finished
 */
int main(int argc, char *argv[]) {

	ConsoleInputController controller;
	cout << controller.runInputLine(argc, argv);

	return 0;
}

