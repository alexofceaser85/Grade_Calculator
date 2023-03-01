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
	ConsoleInputController::ConsoleInputController() {
		this->manager = GradesManager();
		this->numberOfColumns = ApplicationSettings::DefaultNumberOfColumns;
		this->columnWidth = ApplicationSettings::DefaultColumnWidth;
		this->shouldDisplayGradeWithOutput = ApplicationSettings::DefaultDisplayGradeWithOutput;
		this->shouldDisplayHistogramWithOuput = ApplicationSettings::DefaultDisplayHistogramWithOutput;
		this->shouldSortStudentGrades = ApplicationSettings::DefaultSortStudentGradesByGrade;
	}

	ConsoleInputController::~ConsoleInputController() {

	}

	const std::string& displayUsageStatement() {
		//TODO Try and clean this up
		static const std::string usageStatement =
				"usage: gradeanalyzerDeCesare infile [outfile] [options]\n"
				"by Alex DeCesare\n"
				"Performs a simple grade analysis of the students and grades contained infile\n"
				"\t infile " 				"\t\t\t" 		"The input file to analyze the grades of\n"
				"\t outfile " 				"\t\t\t" 		"The output file to write the output to\n"
				"options:\n"
				"\t --help " 				"\t\t\t" 		"Displays this usage statement\n"
				"\t -c <number>" 			"\t\t\t" 		"Changes the number of output columns to the number specified\n"
				"\t\t\t\t\t" 								"The default number of columns is 4.\n"
				"\t -a <first last grade>" 	"\t\t" 			"Add the specified students (case insensitive) to the output.\n"
				"\t\t\t\t\t" 								"E.g., -a john doe 85 would add john doe with a grade of 85\n"
				"\t -g" 					"\t\t\t\t" 		"Displays student grade with the output\n"
				"\t -h" 					"\t\t\t\t" 		"Displays a histogram of the grades in addition to other output\n"
				"\t -sg" 					"\t\t\t\t" 		"Displays the output with the student grade displayed and sorted\n"
				"\t\t\t\t\t"								"by the student's grade in descending order. This will automatically\n"
				"\t\t\t\t\t"								"display the student's grade in the output even if -g is not specified\n"
				"\t\t\t\t\t"								"on the command line.\n"
				"\t -w <number>"			"\t\t\t" 		"Changes the column width for the output columns.\n"
				"\t\t\t\t\t" 								"The default column width is 20\n";
		return usageStatement;
	}

	const std::string ConsoleInputController::changeNameCasing(const std::string &nameToTransform) {
		std::string transformedString = nameToTransform;
		transform(transformedString.begin(), transformedString.end(), transformedString.begin(), ::tolower);
		transformedString[0] = toupper(transformedString[0]);
		return transformedString;
	}

	void ConsoleInputController::addGradeOutput(const Grade& grade, vector<std::string> &outputForGrade) {
		std::string casedFirstName = this->changeNameCasing(grade.getFirstName());
		std::string casedLastName = this->changeNameCasing(grade.getLastName());

		std::string outputForStudent = casedFirstName + " " + casedLastName;

		if (this->shouldDisplayGradeWithOutput) {
			outputForStudent += ":" + std::to_string(grade.getGrade());
		}

		outputForGrade.push_back(outputForStudent);
	}

	bool ConsoleInputController::IsGradeWithinLetterValues(const Grade& grade, int letterIndex) {
		return grade.getGrade() >= ApplicationSettings::MinimumGradeValues[letterIndex] && grade.getGrade() <= ApplicationSettings::MaximumGradeValues[letterIndex];
	}

	const vector<std::string> ConsoleInputController::getGradesOutput(vector<Grade> &grades, int letterIndex) {
		vector<std::string> outputForGrade;

		for (Grade grade : grades) {
			if (this->IsGradeWithinLetterValues(grade, letterIndex)) {
				this->addGradeOutput(grade, outputForGrade);
			}
		}

		return outputForGrade;
	}

	const std::string ConsoleInputController::displayGradeInformation(vector<std::string> &outputForGrade, int letterIndex) {
		std::stringstream output;
		output << "Students earning an " << ApplicationSettings::GradeLetters[letterIndex] << ":" << endl;
		int currentColumn = 1;

		for (string gradeOutput : outputForGrade) {
			output << std::left << setw(this->columnWidth) << gradeOutput;

			if (currentColumn == this->numberOfColumns) {
				currentColumn = 1;
				output << "\n";
			} else {
				currentColumn++;
			}
		}

		currentColumn = 1;
		output << endl << endl;
		return output.str();
	}

	const vector<Grade> ConsoleInputController::getGrades() {
		if (this->shouldSortStudentGrades) {
			return this->manager.getGradesSortedByGradeValue();
		} else {
			return this->manager.getGradesSortedByLastName();
		}
	}

	const std::stringstream ConsoleInputController::displayGradesOutput() {
		std::stringstream output;

		vector<Grade> grades = this->getGrades();

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

	const std::string ConsoleInputController::buildHistogramForGrade(vector<Grade> &grades, int letterIndex) {
		std::stringstream outputForGrade;
		outputForGrade << ApplicationSettings::GradeLetters[letterIndex] << ": ";

		for (Grade grade : grades) {
			if (this->IsGradeWithinLetterValues(grade, letterIndex)) {
				outputForGrade << "*";
			}
		}

		outputForGrade << endl;
		return outputForGrade.str();
	}

	const std::string ConsoleInputController::buildHistogram(vector<Grade> &grades) {
		std::stringstream output;
		for (int letterIndex = 0; letterIndex < ApplicationSettings::GradeLettersSize; letterIndex++) {
			output << this->buildHistogramForGrade(grades, letterIndex);
		}

		return output.str();
	}

	const std::string ConsoleInputController::displayGradesHistogram() {
		vector<Grade> grades = this->manager.getGradesSortedByGradeValue();
		std::stringstream output;

		output << endl << "Grade histogram:" << endl;
		output << this->buildHistogram(grades);

		return output.str();
	}

	std::string ConsoleInputController::runInputLine(int argc, char* argv[]) {
		try {
			int index = 1;

			std::string infile = "";
			std::string outfile = "";

			while (index < argc) {
				std::string arg = argv[index];

				if (arg == "--help") {
					return displayUsageStatement();
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

					Grade gradeToAdd = Grade(firstName, lastName, grade);
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
					return displayUsageStatement();
				}
			}

			std::string gradesOutput = displayGradesOutput().str();

			if (!outfile.empty()) {
				this->manager.saveGradesData(outfile, gradesOutput);
			}

			return gradesOutput;
		}
		catch(const std::invalid_argument& e) {
			return displayUsageStatement();
		}
		catch(const std::logic_error& e) {
			return displayUsageStatement();
		}
	}
}

