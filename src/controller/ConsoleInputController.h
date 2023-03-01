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
	/**
	 * The controller for the console input
	 */
	class ConsoleInputController {
	private:
		GradesManager manager;
		int numberOfColumns;
		int columnWidth;
		bool shouldDisplayGradeWithOutput;
		bool shouldDisplayHistogramWithOuput;
		bool shouldSortStudentGrades;

		const std::string changeNameCasing(const std::string &nameToTransform);
		void addGradeOutput(const StudentGrade& grade, vector<std::string> &outputForGrade);
		bool isGradeWithinLetterValues(const StudentGrade &grade, int letterIndex);
		const vector<std::string> getGradesOutput(vector<StudentGrade> &grades, int letterIndex);
		const std::string displayGradeInformation(vector<std::string> &outputForGrade, int letterIndex);
		const vector<StudentGrade> getGrades();
		const std::stringstream displayGradesOutput();

		const std::string buildHistogramForGrade(vector<StudentGrade> &grades, int letterIndex);
		const std::string buildHistogram(vector<StudentGrade> &grades);
		const std::string displayGradesHistogram();
	public:
		/**
		 * The constructor for the console input controller
		 *
		 * Precondition: None
		 * Postcondition: None
		 */
		ConsoleInputController();
		/**
		 * The destructor for the console input controller
		 *
		 * Precondition: None
		 * Postcondition: None
		 */
		virtual ~ConsoleInputController();
		/**
		 * Runs a line of input from the user
		 *
		 * Precondition: None
		 * Postcondition: None
		 *
		 * Param: argc the number of arguments
		 * Param: argv the arguments
		 */
		std::string runInputLine(int argc, char* argv[]);
	};
}
#endif /* CONTROLLER_CONSOLEINPUTCONTROLLER_H_ */
