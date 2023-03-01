/*
 * ConsoleInputController.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "ConsoleInputController.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "GradesManager.h"

#include "ApplicationSettings.h"

using namespace settings;

using namespace model;
using namespace std;

namespace controller {
	const std::string ConsoleInputController::changeNameCasing(const std::string &nameToTransform) {
		std::string transformedString = nameToTransform;
		transform(transformedString.begin(), transformedString.end(), transformedString.begin(), ::tolower);
		transformedString[0] = toupper(transformedString[0]);
		return transformedString;
	}

	void ConsoleInputController::addGradeOutput(const StudentGrade& grade, vector<std::string> &outputForGrade) {
		std::string casedFirstName = this->changeNameCasing(grade.getFirstName());
		std::string casedLastName = this->changeNameCasing(grade.getLastName());

		std::string outputForStudent = casedFirstName + " " + casedLastName;

		if (this->shouldDisplayGradeWithOutput) {
			outputForStudent += ":" + std::to_string(grade.getGrade());
		}

		outputForGrade.push_back(outputForStudent);
	}

	bool ConsoleInputController::isGradeWithinLetterValues(const StudentGrade& grade, int letterIndex) {
		return grade.getGrade() >= ApplicationSettings::MinimumGradeValues[letterIndex] && grade.getGrade() <= ApplicationSettings::MaximumGradeValues[letterIndex];
	}

	const vector<std::string> ConsoleInputController::getGradesOutput(vector<StudentGrade> &grades, int letterIndex) {
		vector<std::string> outputForGrade;

		for (StudentGrade grade : grades) {
			if (this->isGradeWithinLetterValues(grade, letterIndex)) {
				this->addGradeOutput(grade, outputForGrade);
			}
		}

		return outputForGrade;
	}

	const std::string ConsoleInputController::displayGradeInformation(vector<std::string> &outputForGrade, int letterIndex) {
		std::stringstream output;
		output << "Students earning an " << ApplicationSettings::GradeLetters[letterIndex] << ":" << endl;
		unsigned int currentColumn = 1;

		for (string gradeOutput : outputForGrade) {
			output << std::left << setw(this->columnWidth) << gradeOutput;

			if (currentColumn % this->numberOfColumns == 0 && currentColumn < outputForGrade.size()) {
				output << endl;
			}
			currentColumn++;
		}

		currentColumn = 1;
		output << endl << endl;
		return output.str();
	}

	const vector<StudentGrade> ConsoleInputController::getGrades() {
		if (this->shouldSortStudentGrades) {
			return this->manager.getGradesSortedByGradeValue();
		} else {
			return this->manager.getGradesSortedByLastName();
		}
	}

	const std::stringstream ConsoleInputController::displayGradesOutput() {
		std::stringstream output;

		vector<StudentGrade> grades = this->getGrades();

		for (int letterIndex = 0; letterIndex < ApplicationSettings::GradeLettersSize; letterIndex++) {
			vector<std::string> outputForGrade = this->getGradesOutput(grades, letterIndex);

			if (!outputForGrade.empty()) {
				output << this->displayGradeInformation(outputForGrade, letterIndex);
			}
		}

		if (this->shouldDisplayHistogramWithOuput) {
			output << this->displayGradesHistogram();
		}

		return output;
	}

	const std::string ConsoleInputController::buildHistogramForGrade(vector<StudentGrade> &grades, int letterIndex) {
		std::stringstream outputForGrade;
		outputForGrade << ApplicationSettings::GradeLetters[letterIndex] << ": ";

		for (StudentGrade grade : grades) {
			if (this->isGradeWithinLetterValues(grade, letterIndex)) {
				outputForGrade << "*";
			}
		}

		outputForGrade << endl;
		return outputForGrade.str();
	}

	const std::string ConsoleInputController::buildHistogram(vector<StudentGrade> &grades) {
		std::stringstream output;
		for (int letterIndex = 0; letterIndex < ApplicationSettings::GradeLettersSize; letterIndex++) {
			output << this->buildHistogramForGrade(grades, letterIndex);
		}

		return output.str();
	}

	const std::string ConsoleInputController::displayGradesHistogram() {
		vector<StudentGrade> grades = this->manager.getGradesSortedByGradeValue();
		std::stringstream output;

		output << endl << "Grade histogram:" << endl;
		output << this->buildHistogram(grades);

		return output.str();
	}

	/**
	 * The constructor for the console input controller
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	ConsoleInputController::ConsoleInputController() {
		this->manager = GradesManager();
		this->numberOfColumns = ApplicationSettings::DefaultNumberOfColumns;
		this->columnWidth = ApplicationSettings::DefaultColumnWidth;
		this->shouldDisplayGradeWithOutput = ApplicationSettings::DefaultDisplayGradeWithOutput;
		this->shouldDisplayHistogramWithOuput = ApplicationSettings::DefaultDisplayHistogramWithOutput;
		this->shouldSortStudentGrades = ApplicationSettings::DefaultSortStudentGradesByGrade;
	}

	/**
	 * The deconstructor for the console input controller
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	ConsoleInputController::~ConsoleInputController() {

	}

	/**
	 * Runs a line of input from the user
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: argc the number of arguments
	 * Param: argv the arguments
	 */
	std::string ConsoleInputController::runInputLine(int argc, char* argv[]) {
		try {
			int index = 1;

			std::string infile = "";
			std::string outfile = "";

			while (index < argc) {
				std::string arg = argv[index];

				if (arg == "--help") {
					return ApplicationSettings::UsageStatement;
				}
				else if (arg == "-c") {
					index++;
					int numberOfOutputColumns = std::stoi(argv[index]);
					index++;
					this->numberOfColumns = numberOfOutputColumns;
				} else if (arg == "-a") {
					index++;
					std::string firstName = argv[index];

					index++;
					std::string lastName = argv[index];

					index++;
					int grade = std::stoi(argv[index]);
					index++;

					StudentGrade gradeToAdd = StudentGrade(firstName, lastName, grade);
					this->manager.add(gradeToAdd);
				} else if (arg == "-g") {
					index++;
					this->shouldDisplayGradeWithOutput = true;
				} else if (arg == "-h") {
					index++;
					this->shouldDisplayHistogramWithOuput = true;
				} else if (arg == "-sg") {
					index++;
					this->shouldDisplayGradeWithOutput = true;
					this->shouldSortStudentGrades = true;
				} else if (arg == "-w") {
					index++;
					int columnWidth = std::stoi(argv[index]);

					index++;
					this->columnWidth = columnWidth;
				} else if (infile.empty()) {
					infile = argv[index];
					index++;

					this->manager.loadFromFile(infile);
				} else if (outfile.empty()) {
					outfile = argv[index];
					index++;
				}
				else {
					return ApplicationSettings::UsageStatement;
				}
			}

			std::string gradesOutput = displayGradesOutput().str();

			if (!outfile.empty()) {
				this->manager.saveGradesData(outfile, gradesOutput);
			}

			return gradesOutput;
		}
		catch(const std::invalid_argument& e) {
			return ApplicationSettings::UsageStatement;
		}
		catch(const std::logic_error& e) {
			return ApplicationSettings::UsageStatement;
		}
	}
}

