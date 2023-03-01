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
		const vector<Grade> getGrades();
		const std::stringstream displayGradesOutput();
		const std::string displayGradesHistogram();
		const std::string changeNameCasing(const std::string &nameToTransform);
		void addGradeOutput(const Grade& grade, vector<std::string> &outputForGrade);
		void addGrades(vector<Grade> &grades);
		bool IsGradeWithinLetterValues(const Grade &grade, int letterIndex);
		const vector<std::string> getGradesOutput(vector<Grade> &grades, int letterIndex);
		const std::string displayGradeInformation(vector<std::string> &outputForGrade, int letterIndex);
		const std::string buildHistogramForGrade(vector<Grade> &grades, int letterIndex);
		const std::string buildHistogram(vector<Grade> &grades);
	public:
		ConsoleInputController();
		virtual ~ConsoleInputController();

		std::string runInputLine(int argc, char* argv[]);
	};
}
#endif /* CONTROLLER_CONSOLEINPUTCONTROLLER_H_ */
