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

using namespace model;
using namespace std;

namespace controller {
	ConsoleInputController::ConsoleInputController() {
		// TODO Auto-generated constructor stub
		this->manager = GradesManager();
		//TODO Extract the magic numbers to a settings class
		this->numberOfColumns = 4;
		this->columnWidth = 20;
		this->shouldDisplayGradeWithOutput = false;
		this->shouldDisplayHistogramWithOuput = false;
		this->shouldSortStudentGrades = false;
	}

	ConsoleInputController::~ConsoleInputController() {
		// TODO Auto-generated destructor stub
	}

	const std::string* displayUsageStatement() {
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
				"\t -a <fist last grade>" 	"\t\t" 			"Add the specified students (case insensitive) to the output.\n"
				"\t\t\t\t\t" 								"E.g., -a john doe 85 would add john doe with a grade of 85\n"
				"\t -g" 					"\t\t\t\t" 		"Displays student grade with the output\n"
				"\t -h" 					"\t\t\t\t" 		"Displays a histogram of the grades in addition to other output\n"
				"\t -sg" 					"\t\t\t\t" 		"Displays the output with the student grade displayed and sorted\n"
				"\t\t\t\t\t"								"by the student's grade in descending order. This will automatically\n"
				"\t\t\t\t\t"								"display the student's grade in the output even if -g is not specified\n"
				"\t\t\t\t\t"								"on the command line.\n"
				"\t -w <number>"			"\t\t\t" 		"Changes the column width for the output columns.\n"
				"\t\t\t\t\t" 								"The default column width is 20\n";
		return &usageStatement;
	}

	const std::stringstream ConsoleInputController::displayGradesOutput() {
		std::stringstream output;
		//TODO Move into a settings file
		const char gradeLetters[5] {'A', 'B', 'C', 'D', 'F'};
		const int minimumGradeValues[5] {90, 80, 70, 60, 0};
		const int maximumGradeValues[5] {100, 89, 79, 69, 59};
		int gradeLettersSize = sizeof(gradeLetters) / sizeof(char);

		vector<Grade> grades;

		if (this->shouldSortStudentGrades) {
			grades = this->manager.getSortedGrades();
		} else {
			grades = this->manager.getGrades();
		}

		//TODO Extact into helper methods
		for (int letterIndex = 0; letterIndex < gradeLettersSize; letterIndex++) {
			vector<string> outputForGrade;

			for (Grade grade : grades) {
				if (grade.getGrade() >= minimumGradeValues[letterIndex] && grade.getGrade() <= maximumGradeValues[letterIndex]) {

					string firstName = grade.getFirstName();
					string lastName = grade.getLastName();

					transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
					transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);

					firstName[0] = toupper(firstName[0]);
					lastName[0] = toupper(lastName[0]);

					string outputForStudent = firstName + " " + lastName;

					if (this->shouldDisplayGradeWithOutput) {
						outputForStudent += ":" + std::to_string(grade.getGrade());
					}

					outputForGrade.push_back(outputForStudent);
				}
			}

			if (!outputForGrade.empty()) {
				output << "Students earning an " << gradeLetters[letterIndex] << ":" << endl;
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
				output << endl;
			}
		}

		if (this->shouldDisplayHistogramWithOuput) {
			output << this->displayGradesHistogram();
		}

		return output;
	}

	const std::string ConsoleInputController::displayGradesHistogram() {
		const char gradeLetters[5] {'A', 'B', 'C', 'D', 'F'};
		const int minimumGradeValues[5] {90, 80, 70, 60, 0};
		const int maximumGradeValues[5] {100, 89, 79, 69, 59};
		int gradeLettersSize = sizeof(gradeLetters) / sizeof(char);

		vector<Grade> grades = this->manager.getGrades();

		std::stringstream output;

		output << endl << "Grade histogram:" << endl;

		//TODO Extact into helper methods
		for (int letterIndex = 0; letterIndex < gradeLettersSize; letterIndex++) {
			string outputForGrade;
			output << gradeLetters[letterIndex] << ": ";

			for (Grade grade : grades) {
				if (grade.getGrade() >= minimumGradeValues[letterIndex] && grade.getGrade() <= maximumGradeValues[letterIndex]) {
					output << "*";
				}
			}

			output << endl;
		}

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
					std::string usageOutput = "\n" + *displayUsageStatement();
					return usageOutput;
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
					std::string usageOutput = "\n" + *displayUsageStatement();
					return usageOutput;
				}
			}

			std::string gradesOutput = displayGradesOutput().str();

			if (!outfile.empty()) {
				this->manager.saveGradesData(outfile, gradesOutput);
			}

			return gradesOutput;
		}
		catch(const std::invalid_argument& e) {
			std::string usageOutput = "\n" + *displayUsageStatement();
			return usageOutput;
		}
		catch(const std::logic_error& e) {
			std::string usageOutput = "\n" + *displayUsageStatement();
			return usageOutput;
		}
	}
}

