/*
 * GradesManager.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include <StudentGrade.h>
#include "FileIO.h"
#include "GradesManager.h"

using namespace std;
using namespace io;

namespace model {
	/**
	 * The constructor for the grades manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	GradesManager::GradesManager() {
		this->grades = vector<StudentGrade>();
	}

	/**
	 * The destructor for the grades manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	GradesManager::~GradesManager() {

	}

	/**
	 * Compares the grades by name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: firstGrade The first grade of the comparison
	 * Param: secondGrade The second grade of the comparison
	 *
	 * Return: The grade comparison
	 */
	bool compareByName(const StudentGrade &firstGrade, const StudentGrade &secondGrade) {
	    if (firstGrade.getLastName() == secondGrade.getLastName()) {
	        return firstGrade.getFirstName() < secondGrade.getFirstName();
	    }
	    return firstGrade.getLastName() < secondGrade.getLastName();
	}

	/**
	 * Compares the grades by grade value
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: firstGrade The first grade of the comparison
	 * Param: secondGrade The second grade of the comparison
	 *
	 * Return: The grade comparison
	 */
	bool compareByGrade (const StudentGrade &firstGrade, const StudentGrade &secondGrade) {
		if (firstGrade.getGrade() == secondGrade.getGrade()) {
			return compareByName(firstGrade, secondGrade);
		}
		return firstGrade.getGrade() > secondGrade.getGrade();
	}

	/**
	 * Adds a grade
	 *
	 * Precondition: None
	 * Postcondition: The grade is added
	 *
	 * Param: grade The grade to add
	 */
	void GradesManager::add(StudentGrade& grade) {
		grades.push_back(grade);
	}

	/**
	 * Gets the grades sorted by last name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The grades sorted by last name
	 */
	vector<StudentGrade> GradesManager::getGradesSortedByLastName() const {
		vector<StudentGrade> sortableGrades = this->grades;
		std::sort(sortableGrades.begin(), sortableGrades.end(), compareByName);
		return sortableGrades;
	}

	/**
	 * Gets the grades sorted by grade value
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The grades sorted by grade value
	 */
	vector<StudentGrade> GradesManager::getGradesSortedByGradeValue() const {
		vector<StudentGrade> sortableGrades = this->grades;
		std::sort(sortableGrades.begin(), sortableGrades.end(), compareByGrade);
		return sortableGrades;
	}

	/**
	 * Loads the grades from file
	 *
	 * Precondition: None
	 * Postcondition: The grades from file are added
	 *
	 * Param: filename The file name to load from
	 */
	void GradesManager::loadFromFile(std::string& filename) {
		vector<StudentGrade> loadedGrades = FileIO::loadGradesFromFile(filename);

		for (StudentGrade grade : loadedGrades) {
			this->grades.push_back(grade);
		}
	}

	/**
	 * Saves the grades to a file
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: filename the name of the file to save to
	 * Param: data the data to save
	 */
	void GradesManager::saveGradesData(std::string& filename, std::string& data) {
		FileIO::saveFileOutput(filename, data);
	}
}
