/*
 * ConsoleInputController.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef CONTROLLER_CONSOLEINPUTCONTROLLER_H_
#define CONTROLLER_CONSOLEINPUTCONTROLLER_H_

#include <iostream>
#include "GradesManager.h"
using namespace model;
using namespace std;

namespace controller {
	class ConsoleInputController {
	private:
		int numberOfColumns;
		int columnWidth;
		GradesManager manager;
	public:
		ConsoleInputController();
		virtual ~ConsoleInputController();

		std::string runInputLine(int argc, char* argv[]);
	};
}
#endif /* CONTROLLER_CONSOLEINPUTCONTROLLER_H_ */
