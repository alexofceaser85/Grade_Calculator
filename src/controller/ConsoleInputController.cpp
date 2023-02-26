/*
 * ConsoleInputController.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "ConsoleInputController.h"
#include <iostream>
#include <iomanip>
#include "GradesManager.h"

using model;
using namespace std;

namespace controller {
	ConsoleInputController::ConsoleInputController() {
		// TODO Auto-generated constructor stub
		this->manager = GradesManager();
		this->numberOfColumns = 4;
		this->columnWidth = 20;
	}

	ConsoleInputController::~ConsoleInputController() {
		// TODO Auto-generated destructor stub
	}

	const std::string* displayUsageStatement() {
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

	std::string ConsoleInputController::runInputLine(int argc, char* argv[]) {
		std::string output = "";

		try {
			int index = 1;

			std::string infile = "";
			std::string outfile = "";

			while (index < argc) {
				std::string arg = argv[index];

				if (arg == "--help") {
					output += "\n" + *displayUsageStatement();
					return output;
				}
				else if (arg == "-c") {
					index++;
					int numberOfOutputColumns = std::stoi(argv[index]);
					index++;

					output += "Setting number of output columns to: " + std::to_string(numberOfOutputColumns) + "\n";
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
					output += "Displaying student grade with output\n";
				} else if (arg == "h") {
					index++;
					output += "Displaying histogram of student grades\n";
				} else if (arg == "-sg") {
					index++;
					output += "Displaying student grades sorted by order\n";
				} else if (arg == "-w") {
					index++;
					int columnWidth = std::stoi(argv[index]);

					index++;

					output += "Setting column width to " + std::to_string(columnWidth) + "\n";
				} else if (infile.empty()) {
					infile = argv[index];
					index++;

					output += "Setting infile to " + infile + "\n";
				} else if (outfile.empty()) {
					outfile = argv[index];
					index++;

					output += "Setting outfile to " + outfile + "\n";
				}
				else {
					output += "\n" + *displayUsageStatement();
					return output;
				}
			}

			return output;
		}
		catch(const std::invalid_argument& e) {
			output += "\n" + *displayUsageStatement();
			return output;
		}
		catch(const std::logic_error& e) {
			output += "\n" + *displayUsageStatement();
			return output;
		}
	}
}

