/*
 * gradeanalyzer.cpp
 *
 *  Created on: Feb 17, 2023
 *      Author: adecesa1
 */

#include <iostream>
using namespace std;

#include "ConsoleInputController.h"
using namespace controller;

int main(int argc, char* argv[]) {

	ConsoleInputController controller;
	cout << controller.runInputLine(argc, argv);

	return 0;
}

