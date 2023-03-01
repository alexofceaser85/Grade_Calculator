/*
 * FileIO.cpp
 *
 *  Created on: Feb 27, 2023
 *      Author: adecesa1
 */

#include "FileIO.h"
#include "ErrorMessages.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>
#include <StudentGrade.h>

using namespace std;
using namespace model;
using namespace errormessages;

namespace io {

/**
 * Loads the grade information from the specified file
 *
 * Precondition: filename.isEmpty() == false
 * Postcondition: None
 *
 * Param: filename The file name to load from
 *
 * Return: The grade information from the file
 */
vector<StudentGrade> FileIO::loadGradesFromFile(std::string& filename) {
	if (filename.empty()) {
		throw std::invalid_argument(ErrorMessages::FileNameToLoadCannotBeEmpty);
	}

	std::vector<StudentGrade> grades;
	std::ifstream gradesFile(filename);
	string line;

	while (std::getline(gradesFile, line)) {
		std::stringstream ss(line);
		std::string firstName;
		std::string lastName;
		std::string grade;

		if (std::getline(ss, firstName, ',') && std::getline(ss, lastName, ',') && std::getline(ss, grade)) {
			grades.push_back(StudentGrade(firstName, lastName, std::stoi(grade)));
		}
	}

	return grades;
}

/**
 * Saves the program output to the specified file
 *
 * Precondition: filename.isEmpty() == false
 * Postcondition: None
 *
 * Param: filename the name of the file to save to
 * Param: data the data to save
 */
void FileIO::saveFileOutput(string& filename, string& fileContents) {
	if (filename.empty()) {
		throw std::invalid_argument(ErrorMessages::FileNameToSaveCannotBeEmpty);
	}

	std::ofstream outputFile(filename);

	if (outputFile.is_open()) {
		outputFile << fileContents;
		outputFile.close();
	}
}

}
