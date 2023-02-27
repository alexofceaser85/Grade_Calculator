/*
 * ConsoleInputController.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef CONTROLLER_CONSOLEINPUTCONTROLLER_H_
#define CONTROLLER_CONSOLEINPUTCONTROLLER_H_

#include <iostream>
#include <sstream>
#include "GradesManager.h"
using namespace model;
using namespace std;

namespace controller {
	class ConsoleInputController {
	private:
		GradesManager manager;
		int numberOfColumns;
		int columnWidth;
		bool shouldDisplayGradeWithOutput;
		bool shouldDisplayHistogramWithOuput;
		bool shouldSortStudentGrades;
		const std::stringstream displayGradesOutput();
		const std::string displayGradesHistogram();
	public:
		ConsoleInputController();
		virtual ~ConsoleInputController();

		std::string runInputLine(int argc, char* argv[]);
	};
}
#endif /* CONTROLLER_CONSOLEINPUTCONTROLLER_H_ */
