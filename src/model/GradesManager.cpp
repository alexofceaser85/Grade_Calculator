/*
 * GradesManager.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "Grade.h"
#include "FileIO.h"
#include "GradesManager.h"

using namespace std;
using namespace io;

namespace model {
	GradesManager::GradesManager() {
		this->grades = vector<Grade>();
	}

	GradesManager::~GradesManager() {
		// TODO Auto-generated destructor stub
	}

	bool compareByName(const Grade &a, const Grade &b) {
		return a.getLastName() < b.getLastName();
	}

	bool compareByGrade (const Grade &a, const Grade &b) {
		return a.getGrade() > b.getGrade();
	}

	void GradesManager::add(Grade& grade) {
		grades.push_back(grade);
	}

	vector<Grade> GradesManager::getGradesSortedByLastName() const {
		vector<Grade> sortableGrades = this->grades;
		std::sort(sortableGrades.begin(), sortableGrades.end(), compareByName);
		return sortableGrades;
	}

	vector<Grade> GradesManager::getGradesSortedByGradeValue() const {
		vector<Grade> sortableGrades = this->grades;
		std::sort(sortableGrades.begin(), sortableGrades.end(), compareByGrade);
		return sortableGrades;
	}

	void GradesManager::loadFromFile(std::string filename) {
		vector<Grade> loadedGrades = FileIO::loadGradesFromFile(filename);

		for (Grade grade : loadedGrades) {
			this->grades.push_back(grade);
		}
	}

	void GradesManager::saveGradesData(std::string filename, std::string data) {
		FileIO::saveFileOutput(filename, data);
	}
}
