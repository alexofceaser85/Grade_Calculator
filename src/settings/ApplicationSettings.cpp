/*
 * ApplicationSettings.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: adecesa1
 */

#include "ApplicationSettings.h"
#include <string>

using namespace std;

namespace settings {
/**
 * The constructor for the application settings
 */
ApplicationSettings::ApplicationSettings() {


}

/**
 * The destructor for the application settings
 */
ApplicationSettings::~ApplicationSettings() {

}

/**
 * The grade letters
 */
const char ApplicationSettings::GradeLetters[5] = {'A', 'B', 'C', 'D', 'F'};
/**
 * The minimum grade values
 */
const int ApplicationSettings::MinimumGradeValues[5] = {90, 80, 70, 60, 0};
/**
 * The maximum grade values
 */
const int ApplicationSettings::MaximumGradeValues[5] = {100, 89, 79, 69, 59};
/**
 * The usage statement
 */
const std::string& ApplicationSettings::UsageStatement =
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

}
