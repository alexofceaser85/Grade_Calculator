/*
 * GradesManager.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "Grade.h"

#include "GradesManager.h"

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
}
