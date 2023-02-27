/*
 * FileIO.cpp
 *
 *  Created on: Feb 27, 2023
 *      Author: adecesa1
 */

#include "FileIO.h"
#include "Grade.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;
using namespace model;

namespace io {
vector<Grade> FileIO::loadGradesFromFile(string filename) {
	std::vector<Grade> grades;
	std::ifstream gradesFile(filename);
	string line;

	while (std::getline(gradesFile, line)) {
		std::stringstream ss(line);
		std::string firstName;
		std::string lastName;
		std::string grade;

		if (std::getline(ss, firstName, ',') && std::getline(ss, lastName, ',') && std::getline(ss, grade)) {
			grades.push_back(Grade(firstName, lastName, std::stoi(grade)));
		}
	}

	return grades;
}

void FileIO::saveFileOutput(string filename, string fileContents) {
	std::ofstream outputFile(filename);

	if (outputFile.is_open()) {
		outputFile << fileContents;
		outputFile.close();
	}
}

}
