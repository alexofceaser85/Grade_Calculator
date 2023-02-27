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

	void GradesManager::add(Grade& grade) {
		grades.push_back(grade);
	}

	vector<Grade> GradesManager::getGrades() const {
		return grades;
	}

	vector<Grade> GradesManager::getSortedGrades() const {
		vector<Grade> sortableGrades = this->grades;
		std::sort(sortableGrades.begin(), sortableGrades.end());
		return sortableGrades;
	}

	void GradesManager::loadFromFile(string filename) {
		vector<Grade> loadedGrades = FileIO::loadGradesFromFile(filename);

		for (Grade grade : loadedGrades) {
			this->grades.push_back(grade);
		}
	}

	void GradesManager::saveGradesData(string filename, string data) {
		FileIO::saveFileOutput(filename, data);
	}
}
